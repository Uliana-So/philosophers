#include "philo_header.h"

void	*start_lunch(void *philo)
{
	t_philo		*philo_here;

	philo_here = (t_philo *)philo;
	philo_here->start_eat = philo_here->data->start_time;
	thinking(philo_here);
	if (philo_here->id % 2 == 0)
		fix_usleep(philo_here->data->eat / 2);
	while (TRUE)
	{
		eating(philo_here);
		sleeping(philo_here);
		thinking(philo_here);
	}
}

void	monitor_philo(pthread_t **treads, t_philo **philo, t_data *data)
{
	int	i;
	int	flag;

	fix_usleep(data->die / 2);
	while (TRUE)
	{
		i = 0;
		flag = TRUE;
		while (i < data->count_philo)
		{
			if (delta_time((*philo)[i].start_eat, get_time()) > data->die)
			{
				print_message(0, DIED, &(*philo)[i],
					delta_time((*philo)->data->start_time, get_time()));
				return (free_philo(treads, data, FALSE));
			}
			if (data->must_eat > 0 && (*philo)[i].count_eat < data->must_eat)
				flag = FALSE;
			i++;
		}
		if (data->must_eat > 0 && flag == TRUE)
			return (free_philo(treads, data, TRUE));
	}
}

// void	create_forks(t_data *data, t_philo **philo)
// {

// 	int			i;
// 	int			count;

// 	i = 0;
// 	count = data->count_philo;

// 	if (!treads)
// 		print_error(ERROR_MEMORY);
// 	data->start_time = get_time();
// 	while (i < count)
// 	{
// 		pthread_create(&treads[i], NULL, start_lunch, &((*philo)[i]));
// 		i++;
// 	}
// 	monitor_philo(&treads, philo, data);
// }

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
	sem_t	*sem_id;
	sem_t	*semaphores;

	philo = malloc(sizeof(t_philo) * (data->count_philo));
	// sem_id = sem_open;
	// semaphores = malloc(sizeof(pthread_mutex_t) * (data->count_philo));
	sem_id = sem_open(semaphores , data->count_philo);
	if (philo)
	{
		create_philos(&philo, data);
		start_lunch_ph(data, &philo);
	}
	else
		print_error(ERROR_MEMORY);
}
