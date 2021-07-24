#include "philo_header.h"

uint64_t	delta_time(uint64_t start, uint64_t now)
{
	return (now - start);
}

uint64_t	get_time(void)
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL))
		print_error(ERROR_TIME);
	return (time.tv_sec * 1000 + time.tv_usec * 0.001);
}

void	fix_usleep(uint64_t msec)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < msec)
		usleep(50);
}
