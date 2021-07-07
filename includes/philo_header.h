#ifndef PHILO_HEADER_H
# define PHILO_HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# define TRUE		1
# define FALSE		0
# define RESET		"\x1b[0m"
# define YELLOW		"\x1b[0;33m"
# define RED		"\x1b[1;31m"

typedef enum e_message
{
	FORK_LEFT,
	FORK_RIGHT,
	EAT,
	SLEEP,
	THINK,
	DIED,
	ERROR_COUNT,
	ERROR_MEMORY,
	ERROR_DATA,
	ERROR_TIME,
}				t_message;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				count_philo;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				died_smb;
	uint64_t		start_time;
	enum e_message	*msg;
}				t_data;

// NEED TO REMOVE
void		check_struct(t_data *data);
void		check_fork(t_philo **threads, int n);

// src
int			main(int argc, char **argv);
void		philo_lunch(t_data *data);
void		create_treads(t_data *data, t_philo **threads);
int			check_data(char **argv, t_data *data);
void		print_message(int n);
void		distribution_of_forks(t_philo **threads,
				pthread_mutex_t **mutexes, t_data *data);

// lib
double		ft_atoi(char *str);
double		isnumber(char *number);
int			ft_isdigit(int c);

// time
uint64_t	get_time(void);
void		fix_usleep(uint64_t msec);

#endif
