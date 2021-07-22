#include "philo_header.h"

void	thinking(t_philo *philo)
{
	print_message(1, THINK, philo,
		delta_time(philo->data->start_time, get_time()));
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->sem_lock);
	sem_wait(philo->data->sem_forks);
	sem_wait(philo->data->sem_forks);
	print_message(1, FORK_LEFT, philo,
		delta_time(philo->data->start_time, get_time()));
	print_message(1, FORK_RIGHT, philo,
		delta_time(philo->data->start_time, get_time()));
	sem_post(philo->data->sem_lock);
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	// sem_wait(philo->data->sem_lock);
	philo->start_eat = get_time();
	sem_post(philo->data->sem_lock);
	print_message(1, EAT, philo,
		delta_time(philo->data->start_time, get_time()));
	fix_usleep(philo->data->eat);
	philo->count_eat += 1;
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
}

void	sleeping(t_philo *philo)
{
	print_message(1, SLEEP, philo,
		delta_time(philo->data->start_time, get_time()));
	fix_usleep(philo->data->sleep);
}
