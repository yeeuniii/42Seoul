/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:07:45 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/18 18:00:26 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include "philosophers.h"
# include "data.h"
# include <pthread.h>
# include <sys/time.h>

struct	s_philosopher;

typedef struct s_table
{
	struct s_philosopher	*philos;
	struct timeval			start_time;
	char					*forks;
	pthread_mutex_t			*mutex_fork;
	int						is_end;
	pthread_mutex_t			mutex_end;
	pthread_mutex_t			mutex_start;
	pthread_mutex_t			mutex_message;
	pthread_t				monitor;
	int						died_id;
}	t_table;

int	init_table(t_table *table, t_data data);
int	destroy_mutex_of_table(t_table *table, int idx);
int	free_table(t_table table);

#endif
