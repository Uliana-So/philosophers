#include "philo_header.h"

int	check_data(char **argv, t_data *data)
{
	data->count_philo = isnumber(argv[1]);
	data->die = isnumber(argv[2]);
	data->eat = isnumber(argv[3]);
	data->sleep = isnumber(argv[4]);
	if (argv[5])
		data->must_eat = isnumber(argv[5]);
	else
		data->must_eat = -1;
	if (data->count_philo == FALSE || data->count_philo > 200
		|| data->must_eat == FALSE
		|| data->die < 60 || data->eat < 60 || data->sleep < 60)
	{
		print_message(ERROR_DATA, 0);
		return (FALSE);
	}
	data->died_smb = FALSE;
	return (TRUE);
}
