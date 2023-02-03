/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:11 by yeepark           #+#    #+#             */
/*   Updated: 2023/02/03 13:13:59 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "data.h"
# include "table.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

# define TAKEN_FORK_MSG "%d %d has taken a fork\n"
# define EATING_MSG "%d %d is eating\n"
# define SLEEPING_MSG "%d %d is sleeping\n"
# define THINKING_MSG "%d %d is thinking\n"
# define DIED_MSG "%d %d died\n"
# define EATING_ENOUGH_MSG "All philosophers have eaten enough\n"

# define FAIL_ALLOCATION 1
# define FAIL_THREAD_CREATE 3
# define FAIL_THREAD_JOIN 4
# define FAIL_PROCESS_CREATE 5
# define FAIL_SEMAPHORE_OPEN 6
# define FAIL_SEMAPHORE_CLOSE 7
# define FAIL_SEMAPHORE_UNLINK 8

# define IS_RUNNING 0
# define IS_DIED 1
# define IS_ENOUGH 2

struct	s_semaphore;

typedef struct s_philosopher
{
	int			id;
	pid_t		pid;
	int			last_time_to_eat;
	t_semaphore	sem_last_time;
	int			number_of_eating;
	t_semaphore	sem_eating;
	pthread_t	monitor;
	t_data		data;
	t_table		*table;
}	t_philosopher;

int		init_philosopher(t_table *table, t_data data, int *errno);

int		create_process(t_table *table, t_data data, int *errno);
int		finish_process(t_table *table, t_data data);
int		run_philo(t_philosopher *philo, t_table *table, t_data data);
void	ft_eat(t_philosopher *philo, t_table *table, int time_to_eat);
void	ft_sleep(t_philosopher *philo, t_table *table, int time_to_sleep);
void	ft_think(t_philosopher *philo, t_table *table);

int		is_running(t_table *table);
void	finish(t_table *table);

int		get_runtime(struct timeval start_time);
void	ft_usleep(t_table *table, int goal_time);
int		print_error(int errno);
void	free_all(t_table *table, int number_of_philos);

#endif
