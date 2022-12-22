/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:44:15 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 16:41:24 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_philosopher;

typedef struct s_table
{
	struct s_philosopher	*philos;
	pthread_t				monitor;
	struct timeval			start_time;
	pthread_mutex_t			*mutex_forks;
	char					*forks;
	int						is_end;
}	t_table;

int		init_table(t_table *table, int number_of_philos);
int		allocate_table(t_table *table, int number_of_philos);
void	free_table(t_table table);

#endif
