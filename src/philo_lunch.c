#include "philo_header.h"

void	start_lunch(t_data *data, t_philo *threads)
{
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
		check_fork(&philo, data->count_philo);
		// start_lunch(data, threads);
	}
	else
		print_message(data->msg, ERROR_MEMORY);
}
