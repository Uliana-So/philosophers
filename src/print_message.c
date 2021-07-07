#include "philo_header.h"

void	print_message(int n)
{
	if (n == FORK_LEFT)
		printf("has taken LEFT fork\n");
	else if (n == FORK_RIGHT)
		printf("has taken RIGHT fork\n");
	else if (n == EAT)
		printf("is eating\n");
	else if (n == SLEEP)
		printf("is sleeping\n");
	else if (n == THINK)
		printf("is thinking\n");
	else if (n == DIED)
		printf(RED "died\n");
		// died_smb = TRUE
	else if (n == ERROR_COUNT)
		printf(RED "Wrong count arguments\n");
	else if (n == ERROR_DATA)
		printf(RED "Wrong argument\n");
	else
		printf(RED "Error memory\n");
	printf(RESET);
}
