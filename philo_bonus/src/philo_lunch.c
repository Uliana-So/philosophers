#include "philo_header.h"

void	*start_lunch(t_philo *philo)
{
	pthread_t	monitor;

	philo->start_eat = philo->data->start_time;
	pthread_create(&monitor, NULL, monitor_philo, philo);
	thinking(philo);
	if (philo->id % 2 == 0)
		fix_usleep(philo->data->eat / 2);
	while (TRUE)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

void	*monitor_philo(void *philo)
{
	int	i;
	int	flag;

	fix_usleep(((t_philo *)philo)->data->die / 2);
	while (TRUE)
	{
		// i = 0;
		flag = TRUE;
		// while (i < ((t_philo *)philo)->data->count_philo)
		// {
			if (delta_time(((t_philo *)philo)[i].start_eat, get_time()) > ((t_philo *)philo)->data->die)
			{
				print_message(0, DIED, &((t_philo *)philo)[i],
					delta_time(((t_philo *)philo)->data->start_time, get_time()));
				// return (free_pthread(treads, data, FALSE));
			}
			if (((t_philo *)philo)->data->must_eat > 0 && ((t_philo *)philo)[i].count_eat < ((t_philo *)philo)->data->must_eat)
				flag = FALSE;
			i++;
		// }
		if (((t_philo *)philo)->data->must_eat > 0 && flag == TRUE)
			// return (free_pthread(treads, data, TRUE));
	}
}

void	create_forks(t_data *data, t_philo **philo)
{
	int			i;
	int			count;

	i = 0;
	count = data->count_philo;
	data->start_time = get_time();
	while (i < count)
	{
		(*philo)[i].pid = fork();
		if ((*philo)[i].pid == 0)
			start_lunch(&((*philo)[i]));
		i++;
	}

}

void	create_philos(t_philo **philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
		(*philo)[i].data = data;
		(*philo)[i].id = i;
		(*philo)[i].count_eat = 0;
		i++;
	}
}

void	philo_lunch(t_data *data)
{
	t_philo	*philo;

	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("lock");
	philo = malloc(sizeof(t_philo) * (data->count_philo));
	data->sem_forks = sem_open("forks", O_CREAT, 0644, data->count_philo);
	data->sem_write = sem_open("write", O_CREAT, 0644, 1);
	data->sem_lock = sem_open("lock", O_CREAT, 0644, 1);
	if (data->sem_forks == SEM_FAILED || data->sem_write == SEM_FAILED ||
		data->sem_lock ==SEM_FAILED)
		print_error(ERROR_SEM);
	else  if (philo)
	{
		create_philos(&philo, data);
		create_philos(data, &philo);
	}
	else
		print_error(ERROR_MEMORY);
}
