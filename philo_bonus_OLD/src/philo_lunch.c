#include "philo_header.h"

void	*start_lunch(t_philo *philo)
{
	pthread_t	monitor;

	philo->start_eat = philo->data->start_time;
	// printf("-----%llu-----\n", delta_time(philo->start_eat, get_time()));	
	pthread_create(&monitor, NULL, monitor_philo, philo);
	thinking(philo);
	while (philo->data->died_smb)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	// pthread_detach(monitor);
	exit (0);
}

void	*monitor_philo(void *philo)
{
	int		i;
	int		count;
	int		flag;
	t_philo	*philo_here;

	count = ((t_philo *)philo)->data->count_philo;
	philo_here = (t_philo *)philo;
	fix_usleep(((t_philo *)philo)->data->die / 2);
	while (TRUE)
	{
		i = 0;
		flag = TRUE;
		while (i < count)
		{
			printf("%d ph --%llu--\n", i, philo_here[i].start_eat);
			printf("--%llu--\n", get_time());
			printf("--%llu--\n\n", delta_time(philo_here[i].start_eat, get_time()));
			if (delta_time(philo_here[i].start_eat, get_time()) > philo_here->data->die)
			{
				// printf("--%llu--\n", delta_time(philo_here[i].start_eat, get_time()));
				print_message(0, DIED, &philo_here[i],
					delta_time(philo_here->data->start_time, get_time()));
				// philo_here[i].data->died_smb = TRUE;
				// return (0);
				// return (free_philo(treads, data, FALSE));
			}
			if (philo_here->data->must_eat > 0 && philo_here[i].count_eat < philo_here->data->must_eat)
				flag = FALSE;
			i++;
		}
		if (philo_here->data->must_eat > 0 && flag == TRUE)
		// {
			philo_here[i].data->died_smb = TRUE;
			// return (free_philo(treads, data, TRUE));
	}
}

void	create_forks(t_data *data, t_philo **philo)
{
	int			i;
	int			count;

	data->start_time = get_time();
	i = 0;
	count = data->count_philo;
	while (i < count)
	{
		(*philo)[i].pid = fork();
		if ((*philo)[i].pid == 0)
			start_lunch(&((*philo)[i]));
		i++;
	}
	waitpid(-1, 0, 0);
	printf("%d\n", i);
	while (i > 0)
	{
		// printf("%d\n",(*philo)[i].pid);
		kill((*philo)[i - 1].pid, SIGKILL);
		i--;
	}
	exit (0);
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
		create_forks(data, &philo);
	}
	else
		print_error(ERROR_MEMORY);
}
