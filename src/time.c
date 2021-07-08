#include "philo_header.h"

uint64_t	get_time(void)
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL))
		print_message(ERROR_TIME, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	fix_usleep(uint64_t msec)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < msec)
		usleep(500);
}
