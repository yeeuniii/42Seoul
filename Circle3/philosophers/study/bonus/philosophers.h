/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:10:20 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/25 11:14:28 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "table.h"
# include "data.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKEN_FORK_MSG "%d %d has taken a fork\n"
# define EATING_MSG "%d %d is eating\n"
# define SLEEPING_MSG "%d %d is sleeping\n"
# define THINKING_MSG "%d %d is thinking\n"
# define DIED_MSG "%d %d died\n"
# define EATING_ENOUGH_MSG "All philosophers have eaten enough\n"

struct	s_table;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	int				right_fork;
	int				left_fork;
	int				number_of_eating;
	pthread_mutex_t	mutex_eating;
	int				last_time_to_eat;
	pthread_mutex_t	mutex_last_time;
	int				delay;
	pthread_mutex_t	mutex_delay;
	struct s_data	data;
	struct s_table	*table;
}	t_philosopher;

int		init_data(t_data *data, int argc, char *argv[]);
int		init_philosopher(t_table *table, t_data data);
void	*run_philo(void *arg);
void	*run_monitor(void *arg);

int		destroy_mutex_of_philosopher(t_table *table, int idx);

void	ft_eat(t_philosopher *philo, t_table *table, t_data data, int *delay);
void	ft_sleep(t_philosopher *philo, t_table *table, t_data data, int *delay);
void	ft_think(t_philosopher *philo, t_table *table);
void	print_message(t_philosopher *philo, t_table *table, char *format);

int		is_running(t_table *table);
void	finish(t_table *table);

int		get_runtime(struct timeval start_time);
void	get_delaytime(t_philosopher *philo, t_data data, int delay);
void	ft_usleep(t_table *table, int goal_time);
void	free_all(t_table *table, int number_of_philos);

#endif
