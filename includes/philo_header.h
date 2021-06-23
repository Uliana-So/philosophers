#ifndef PHILO_HEADER_H
# define PHILO_HEADER_H

# include <unistd.h>
# include <stdio.h>
# define TRUE       1
# define FALSE      0
# define RESET      "\x1b[0m"
# define YELLOW     "\x1b[0;33m"
# define RED        "\x1b[1;31m"

typedef enum s_message
{
    FORK,
    EAT,
    SLEEP,
    THINK,
    DIED,
    ERROR_COUNT,
    ERROR_DATA,
}            t_message;

//typedef struct s_philo
//{
//
//}              t_philo;

typedef struct  s_data
{
    int count_philo;
    int die;
    int eat;
    int sleep;
    int must_eat;
    int died_smb;
    enum s_message  msg;
}               t_data;

// NEED TO REMOVE
void    check_struct(t_data *data);

// src
int       main(int argc, char **argv);
int       check_data(char **argv, t_data *data);
int       print_message(t_message *msg, int n);

// lib
double    ft_atoi(char *str);
double    isnumber(char *number);
int       ft_isdigit(int c);


#endif
