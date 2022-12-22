/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:20:15 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 20:21:07 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

struct					s_table;

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

void	*run_philosopher(void *arg);

#endif
