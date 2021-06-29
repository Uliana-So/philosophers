#include "philo_header.h"

void	distribution_of_forks(pthread_t **threads, pthread_mutex_t **mutexes)
{
	int	i;

	i = 0;
	while (threads[i])
	{
		// if(i == 0)
		pthread_mutex_init(&mutexes[i], NULL);
		

	}
}




	// head = *list;
	// if (!head)
	// {
	// 	*list = new_data;
	// 	new_data->next = NULL;
	// 	new_data->prev = NULL;
	// }
	// else
	// {
	// 	head->next = new_data;
	// 	new_data->prev = head;
	// 	*list = new_data;
	// }