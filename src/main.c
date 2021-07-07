#include "philo_header.h"

void    check_struct(t_data *data)
{
	printf(RED "===== DATA =====\n");
	printf(YELLOW "count        %d\n", data->count_philo);
	printf("die          %d\n", data->die);
	printf("eat          %d\n", data->eat);
	printf("sleep        %d\n", data->sleep);
	printf("must_eat     %d\n\n" RESET, data->must_eat);
}

void    check_fork(t_philo **philo, int n)
{
	int i = 0;

	while (i < n)
	{
	printf("%d left -> %p right -> %p\n", (*philo)[i].id, (*philo)[i].left, (*philo)[i].right);
		i++;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (check_data(argv, &data))
		{
			check_struct(&data);
			philo_lunch(&data);
		}
		// check_struct(&data);
	}
	else
		print_message(ERROR_COUNT);
	exit(0);
}
