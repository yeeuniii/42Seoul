/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:20:15 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/30 11:13:33 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

struct					s_table;

typedef struct s_philosopher
{
	struct s_data	data;
	struct s_table	*table;
	pthread_t		thread;
	int				number;
	int				left_fork;
	int				right_fork;
	int				last_time_to_eat;
	pthread_mutex_t	mutex_last_time;
	int				eating_time;
	pthread_mutex_t	mutex_eating_time;
}	t_philosopher;

int		init_philosophers(t_table *table, t_data data);
int		destroy_mutex_of_philosopher(t_philosopher *philos, int idx);

void	*run_philosopher(void *arg);

#endif
