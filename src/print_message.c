#include "philo_header.h"

void	print_message(t_message *msg, int n)
{
	if (n == FORK)
		printf("has taken a fork\n");
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
		printf(RED "Wrong count arguments\n" RESET);
	else if (n == ERROR_MEMORY)
		printf(RED "Error memory\n" RESET);
	else
		printf(RED "Wrong data\n" RESET);
	printf(RESET);
}
