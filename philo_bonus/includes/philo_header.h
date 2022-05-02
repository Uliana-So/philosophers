#ifndef PHILO_HEADER_H
# define PHILO_HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>
# define TRUE		1
# define FALSE		0
# define RESET		"\x1b[0m"
# define RED		"\x1b[1;31m"
# define FORK_LEFT	"%llu philo %d has taken LEFT fork\n"
# define FORK_RIGHT	"%llu philo %d has taken RIGHT fork\n"
# define EAT		"\x1b[0;33m%llu philo %d is eating\x1b[0m\n"
# define SLEEP		"%llu philo %d is sleeping\n"
# define THINK		"%llu philo %d is thinking\n"
# define DIED		"\x1b[1;31m%llu philo %d died\x1b[0m\n"
# define ERROR_COUNT	"Wrong count arguments\n"
# define ERROR_MEMORY	"Error memory\n"
# define ERROR_DATA	"Wrong argument\n"
# define ERROR_MUTEX	"Error mutex\n"
# define ERROR_TIME	"Error time\n"
# define ERROR_SEM	"Error semaphore\n"

typedef struct s_philo
{
	int			id;
	pid_t			pid;
	uint64_t		start_eat;
	int			count_eat;
	struct s_data		*data;
}		t_philo;

typedef struct s_data
{
	int			count_philo;
	uint64_t		die;
	uint64_t		eat;
	uint64_t		sleep;
	int			must_eat;
	uint64_t		start_time;
	sem_t			*sem_forks;
	sem_t			*sem_write;
	sem_t			*sem_lock;
}		t_data;

// src
int		main(int argc, char **argv);
void		philo_lunch(t_data *data);
void		create_forks(t_data *data, t_philo **threads);
int		check_data(char **argv, t_data *data);
void		sleeping(t_philo *philo);
void		eating(t_philo *philo);
void		take_forks(t_philo *philo);
void		thinking(t_philo *philo);
void		*monitor_philo(void *philo);
void		kill_pid(t_philo *philo, int count);

// lib
double		ft_atoi(char *str);
double		isnumber(char *number);
int		ft_isdigit(int c);

// message
void		print_message(int flag, const char *str,
				t_philo *philo, uint64_t time);
void		print_error(const char *str);

// time
uint64_t	get_time(void);
void		fix_usleep(uint64_t msec);
uint64_t	delta_time(uint64_t start, uint64_t now);

#endif
