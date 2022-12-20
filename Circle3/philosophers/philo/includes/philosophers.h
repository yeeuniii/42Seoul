/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:38 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/20 15:30:41 by yeepark          ###   ########.fr       */
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

# define TAKEN_FORK_MSG "%dms %d has taken a fork\n"
# define EATING_MSG "%dms %d is eating\n"
# define SLEEPING_MSG "%dms %d is sleeping\n"
# define THINKING_MSG "%dms %d is thinking\n"
# define DIED_MSG "%dms %d is died\n"

typedef struct s_philosopher
{
	struct s_table	table;
	pthread_t		thread;
	int				number;
	int				left_fork;
	int				right_fork;
	int				last_time_to_eat;
	int				eating_time;
	int				is_died;
}	t_philosopher;

void	*run(void *philo);

int		print_error_message(void);
int		get_time(struct timeval start_time);

#endif
