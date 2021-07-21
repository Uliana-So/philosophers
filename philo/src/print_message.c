#include "philo_header.h"

void	print_message(int flag, const char *str, t_philo *philo, uint64_t time)
{
	pthread_mutex_lock(&philo->data->output);
	printf(str, time, philo->id + 1);
	if (flag)
		pthread_mutex_unlock(&philo->data->output);
}

void	print_error(const char *str)
{
	printf(RED "%s" RESET, str);
}
