#include "philo_header.h"

void	start_lunch(t_data *data, pthread_t *threads)
{
	return ;
}

void	philo_lunch(t_data *data)
{
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;

	threads = malloc(sizeof(t_philo) * data->count_philo);
	mutexes = malloc(sizeof(pthread_mutex_t) * data->count_philo);
	if (threads && mutexes)
	{
		init_struct(&threads, &mutexes);
		distribution_of_forks(data, threads);
	}
	else
		print_message(data->msg, ERROR_MEMORY);
}
