/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:11 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/26 14:23:33 by yeepark          ###   ########.fr       */
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

struct s_semaphore;

typedef struct s_philosopher
{
	int			id;
	pid_t		pid;
	int			last_time_to_eat;
	t_semaphore	sem_last_time;
	int			number_of_eating;
	t_semaphore	sem_eating;
	int			delay;
	t_semaphore	sem_delay;
} t_philosopher;

int		init_philosopher(t_table *table, t_data data);

int		create_process(t_table *table, t_data data);
void	run_philo(t_philosopher *philo, t_table *table, t_data data);

void	ft_eat(t_philosopher *philo, t_table *table, int time_to_eat);
void	ft_sleep(t_philosopher *philo, t_table *table, int time_to_sleep);
void	ft_think(t_philosopher *philo, t_table *table);

int		get_runtime(struct timeval start_time);
int		is_running(t_table *table);
void	finish(t_table *table);
void	ft_usleep(t_table *table, int goal_time);

#endif
