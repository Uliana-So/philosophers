#include "philo_header.h"

void	*take_forks(void *philo)
{
	static int	i = 0;
	t_philo		*philo_here;
	// printf("%p take %d\n\n", philo, i);
	// i++;
	philo_here = (t_philo *)philo;
	// printf("here\n");
	printf("died %d\n", philo_here->data->died_smb);
	while (philo_here->data->died_smb == FALSE)
	{
		printf("%p take %d\n\n", philo, i);
		i++;
	}

}

void	start_lunch(t_data *data, t_philo **philo)
{
	pthread_t	*treads;
	int			i;

	i = 0;
	// check_fork(philo, data->count_philo);
	treads = malloc(sizeof(pthread_t) * data->count_philo);
	if (!treads)
		print_message(data->msg, ERROR_MEMORY);
	data->start_time = get_time();
	// printf("%ld\n", start_time);
	while (i < data->count_philo)
	{
		// printf("here %p %d %d\n", &treads[i], i, data->died_smb);
		pthread_create(&treads[i], NULL, take_forks, &((*philo)[i]));
		// pthread_detach(treads[i]);
		usleep(1000);
		i++;
	}

	return ;
}

void	distribution_of_forks(t_philo **philo, pthread_mutex_t **mutexes, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
		if (pthread_mutex_init(&(*mutexes)[i], NULL) != 0)
			printf("ERROR\n");
		(*philo)[i].data = data;
		(*philo)[i].id = i;
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
		// check_fork(&philo, data->count_philo);
		start_lunch(data, &philo);
	}
	else
		print_message(data->msg, ERROR_MEMORY);
}
