#include "philo_header.h"

void	thinking(t_philo *philo)
{
	print_message(1, THINK, philo,
		delta_time(philo->data->start_time, get_time()));
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	print_message(1, FORK_LEFT, philo,
		delta_time(philo->data->start_time, get_time()));
	print_message(1, FORK_RIGHT, philo,
		delta_time(philo->data->start_time, get_time()));
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->check_die);
	philo->start_eat = get_time();
	pthread_mutex_unlock(&philo->check_die);
	print_message(1, EAT, philo,
		delta_time(philo->data->start_time, get_time()));
	fix_usleep(philo->data->eat);
	philo->count_eat += 1;
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	sleeping(t_philo *philo)
{
	philo->start_sleep = get_time();
	print_message(1, SLEEP, philo,
		delta_time(philo->data->start_time, get_time()));
	fix_usleep(philo->data->sleep);
}

void	free_pthread(pthread_t **treads, t_data *data, int flag)
{
	int	i;

	i = data->count_philo;
	if (flag)
		pthread_mutex_lock(&data->output);
	while (i > 0)
	{
		pthread_detach((*treads)[i - 1]);
		i--;
	}
	free(*treads);
	return ;
}
