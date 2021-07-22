#include "philo_header.h"

void	print_message(int flag, const char *str, t_philo *philo, uint64_t time)
{
	sem_wait(philo->data->sem_write);
	printf(str, time, philo->id + 1);
	if (flag)
		sem_post(philo->data->sem_write);
}

void	print_error(const char *str)
{
	printf(RED "%s" RESET, str);
	return ;
}
