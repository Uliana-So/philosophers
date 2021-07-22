#include "philo_header.h"

double	ft_atoi(char *str)
{
	int		i;
	double	result;
	int		minus;

	i = 0;
	result = 0;
	minus = 1;
	while (str[i] && ((str[i] > 7 && str[i] < 14) || str[i] == 32))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = 10 * result + (str[i] - '0') * minus;
		i++;
		if (result < 0 && minus > 0)
			return (-1);
		else if (result > 0 && minus < 0)
			return (FALSE);
	}
	return (result);
}

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (TRUE);
	return (FALSE);
}

double	isnumber(char *number)
{
	int	i;

	i = 0;
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]))
			return (FALSE);
		i++;
	}
	return (ft_atoi(number));
}

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
		|| data->die < 60 || data->eat < 60 || data->sleep < 60
		|| pthread_mutex_init(&data->output, NULL) != 0)
	{
		print_error(ERROR_DATA);
		return (FALSE);
	}
	return (TRUE);
}
