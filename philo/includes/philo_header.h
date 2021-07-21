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
# define RED		"\x1b[1;31m"
# define FORK_LEFT	"%llu philo %d has taken LEFT fork\n"
# define FORK_RIGHT	"%llu philo %d has taken RIGHT fork\n"
# define EAT		"\x1b[0;33m%llu philo %d is eating\n\x1b[0m"
# define SLEEP		"%llu philo %d is sleeping\n"
# define THINK		"%llu philo %d is thinking\n"
# define DIED		"\x1b[1;31m%llu philo %d died\n\x1b[0m"
# define ERROR_COUNT	"Wrong count arguments\n"
# define ERROR_MEMORY	"Error memory\n"
# define ERROR_DATA		"Wrong argument\n"
# define ERROR_MUTEX	"Error mutex\n"
# define ERROR_TIME		"Error time\n"

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	check_die;
	uint64_t		start_eat;
	uint64_t		start_sleep;
	int				count_eat;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				count_philo;
	uint64_t		die;
	uint64_t		eat;
	uint64_t		sleep;
	int				must_eat;
	int				died_smb;
	pthread_mutex_t	output;
	uint64_t		start_time;
}				t_data;

// src
int			main(int argc, char **argv);
void		philo_lunch(t_data *data);
void		create_treads(t_data *data, t_philo **threads);
int			check_data(char **argv, t_data *data);

void		distribution_of_forks(t_philo **philo,
				pthread_mutex_t **mutex, t_data *data);
void		sleeping(t_philo *philo);
void		eating(t_philo *philo);
void		take_forks(t_philo *philo);
void		thinking(t_philo *philo);
void		free_pthread(pthread_t **treads, t_data *data, int flag);
void		monitor_philo(pthread_t **treads, t_philo **philo, t_data *data);

// lib
double		ft_atoi(char *str);
double		isnumber(char *number);
int			ft_isdigit(int c);

// message
void		print_message(int flag, const char *str,
				t_philo *philo, uint64_t time);
void		print_error(const char *str);

// time
uint64_t	get_time(void);
void		fix_usleep(uint64_t msec);
uint64_t	delta_time(uint64_t start, uint64_t now);

#endif
