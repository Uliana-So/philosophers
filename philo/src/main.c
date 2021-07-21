#include "philo_header.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (check_data(argv, &data))
			philo_lunch(&data);
	}
	else
		print_error(ERROR_COUNT);
	exit(0);
}
