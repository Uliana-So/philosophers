#include "philo_header.h"

void	*take_forks(void *philo)
{
	static int	i = 0;
	printf("%p take %d\n\n", philo, i);
	i++;
}

void	start_lunch(t_data *data, t_philo **philo)
{
	uint64_t	start_time;
	pthread_t	*treads;
	int			i;

	i = 0;
	// check_fork(philo, data->count_philo);
	treads = malloc(sizeof(pthread_t) * data->count_philo);
	if (!treads)
		print_message(data->msg, ERROR_MEMORY);
	start_time = get_time();
	// printf("%ld\n", start_time);
	while (i < data->count_philo)
	{
		printf("here %p %d\n", &treads[i], i);
		pthread_create(&treads[i], NULL, take_forks, &((*philo)[i]));
		i++;
	}
	return ;
}

void	distribution_of_forks(t_philo **philo, pthread_mutex_t **mutexes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&(*mutexes)[i], NULL) != 0)
			printf("ERROR\n");
		(*philo)[i].id = i;
		(*philo)[i].left = &(*mutexes)[i];
		if (i == count - 1)
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
		distribution_of_forks(&philo, &mutexes, data->count_philo);
		// check_fork(&philo, data->count_philo);
		start_lunch(data, &philo);
	}
	else
		print_message(data->msg, ERROR_MEMORY);
}
