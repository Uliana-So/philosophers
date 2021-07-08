#include "philo_header.h"

// void	write_message(int n)
// {
// 	if (n == FORK_LEFT)
// 		write(1, "has taken LEFT fork\n", 21);
// 	else if (n == FORK_RIGHT)
// 		write(1, "has taken RIGHT fork\n", 22);
// 	else if (n == EAT)
// 		write(1, " is eating\n", 11);
// 	else if (n == SLEEP)
// 		write(1, " is sleeping\n", 13);
// 	else if (n == THINK)
// 		write(1, " is thinking\n", 13);
// 	else if (n == DIED)
// 		write(1, RED " died\n", 14);
// 		// died_smb = TRUE
// 	else if (n == ERROR_COUNT)
// 		write(1, RED "Wrong count arguments\n", 30);
// 	else if (n == ERROR_MEMORY)
// 		write(1, RED "Error memory\n", 21);
// 	else if (n == ERROR_DATA)
// 		write(1, RED "Wrong data\n", 19);
// 	else
// 		write(1, RED "Wrong time\n", 19);
// 	write(1, RESET, 5);
// }

void	print_message(int n, int philo)
{
	if (n == FORK_LEFT)
		printf("philo %d has taken LEFT fork\n", philo);
	else if (n == FORK_RIGHT)
		printf("philo %d has taken RIGHT fork\n", philo);
	else if (n == EAT)
		printf("philo %d is eating\n", philo);
	else if (n == SLEEP)
		printf("philo % is sleeping\n", philo);
	else if (n == THINK)
		printf("philo %d is thinking\n", philo);
	else if (n == DIED)
		printf(RED "philo %d died\n", philo);
		// died_smb = TRUE
	else if (n == ERROR_COUNT)
		printf(RED "Wrong count arguments\n");
	else if (n == ERROR_DATA)
		printf(RED "Wrong argument\n");
	else
		printf(RED "Error memory\n");
	printf(RESET);
}