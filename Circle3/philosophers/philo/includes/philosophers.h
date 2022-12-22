/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:38 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 16:44:03 by yeepark          ###   ########.fr       */
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

# define TAKEN_FORK_MSG "%d %d has taken a fork\n"
# define EATING_MSG "%d %d is eating\n"
# define SLEEPING_MSG "%d %d is sleeping\n"
# define THINKING_MSG "%d %d is thinking\n"
# define DIED_MSG "%d %d is died\n"

struct	s_table;

typedef struct s_philosopher
{
	struct s_data	data;
	struct s_table	table;
	pthread_t		thread;
	int				number;
	int				left_fork;
	int				right_fork;
	int				last_time_to_eat;
	int				eating_time;
	int				is_died;
}	t_philosopher;

int		init(t_table *table, t_data data);
void	set_fork(t_philosopher *philo);

int		create_thread(t_table *table);
void	*run(void *philo);

int		print_error_message(void);
int		get_time(struct timeval start_time);

#endif
