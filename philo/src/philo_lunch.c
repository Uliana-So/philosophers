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
				return (free_pthread(treads, data, FALSE));
			}
			if (data->must_eat > 0 && (*philo)[i].count_eat < data->must_eat)
				flag = FALSE;
			i++;
		}
		if (data->must_eat > 0 && flag == TRUE)
			return (free_pthread(treads, data, TRUE));
	}
}

void	create_treads(t_data *data, t_philo **philo)
{
	pthread_t	*treads;
	int			i;
	int			count;

	i = 0;
	count = data->count_philo;
	treads = malloc(sizeof(pthread_t) * count);
	if (!treads)
		print_error(ERROR_MEMORY);
	data->start_time = get_time();
	while (i < count)
	{
		pthread_create(&treads[i], NULL, start_lunch, &((*philo)[i]));
		i++;
	}
	monitor_philo(&treads, philo, data);
}

void	distribution_of_forks(t_philo **philo, pthread_mutex_t **mutexes,
							 t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
		if (pthread_mutex_init(&(*mutexes)[i], NULL) != 0 ||
			pthread_mutex_init(&(*philo)[i].block_die, NULL) != 0)
			print_error(ERROR_MUTEX);
		(*philo)[i].data = data;
		(*philo)[i].id = i;
		(*philo)[i].count_eat = 0;
		(*philo)[i].left = &(*mutexes)[i];
		if (i == data->count_philo - 1)
			(*philo)[0].right = (*philo)[i].left;
		else
			(*philo)[i + 1].right = &(*mutexes)[i];
		i++;
	}
}

void	philo_lunch(t_data *data)
{
	t_philo			*philo;
	pthread_mutex_t	*mutexes;

	philo = malloc(sizeof(t_philo) * (data->count_philo));
	mutexes = malloc(sizeof(pthread_mutex_t) * (data->count_philo));
	if (philo && mutexes)
	{
		distribution_of_forks(&philo, &mutexes, data);
		create_treads(data, &philo);
	}
	else
		print_error(ERROR_MEMORY);
}
