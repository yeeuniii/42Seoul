/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:43:09 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 15:20:12 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include "philosopher.h"
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

struct	s_philosopher;

typedef struct s_semaphore
{
	sem_t	*sem;
	char	*name;
}	t_semaphore;

typedef struct s_table
{
	struct s_philosopher	*philos;
	struct timeval			start_time;
	t_semaphore				forks;
	int						is_end;
	t_semaphore				sem_end;
	t_semaphore				sem_message;
	t_data					data;
} t_table;

int		init_table(t_table *table, t_data data, int *errno);
int		init_fork(t_semaphore *fork, t_data data);

void	*run_monitor(void *arg);

#endif
