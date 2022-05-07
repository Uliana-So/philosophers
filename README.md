# philosophers

## About project
One or more philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping.
- in ./philo uses treads and mutexes
- in ./philo_bonus uses forks

## Requirements for Linux
- make
- gcc

## Program arguments
* number_philosophers: is the number of philosophers and also the number of forks;
* time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies;
* time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks;
* time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping;
* number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

## Compiling
```
make
```
## Start project
```
./philo 3 210 100 100 2
```
##### Result
```
0 philo 1 is thinking
1 philo 1 has taken LEFT fork
1 philo 1 has taken RIGHT fork
1 philo 1 is eating
0 philo 2 is thinking
0 philo 3 is thinking
51 philo 2 has taken LEFT fork
101 philo 1 is sleeping
101 philo 2 has taken RIGHT fork
101 philo 2 is eating
101 philo 3 has taken LEFT fork
201 philo 1 is thinking
201 philo 1 has taken LEFT fork
201 philo 2 is sleeping
201 philo 3 has taken RIGHT fork
201 philo 3 is eating
211 philo 1 died
```
