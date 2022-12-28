/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:38 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/28 16:59:24 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h> //memset
# include <sys/time.h>
# include <pthread.h>
# include "data.h"
# include "table.h"
# include "philosopher.h"

# define TAKEN_FORK_MSG "%d %d has taken a fork\n"
# define EATING_MSG "%d %d is eating\n"
# define SLEEPING_MSG "%d %d is sleeping\n"
# define THINKING_MSG "%d %d is thinking\n"
# define DIED_MSG "%d %d is died\n"

typedef struct timeval	t_timeval;

int		init(t_table *table, t_data data);
void	set_fork(t_philosopher *philo);
int		destroy_mutex(t_table *table, int idx);

int		create_thread(t_table *table, t_data data);
void	*run(void *philo);

int		print_error_message(void);
int		get_runtime(t_timeval start_time);
void	ft_usleep(t_timeval start_time, int function_call_time, int time_to_do);

#endif
