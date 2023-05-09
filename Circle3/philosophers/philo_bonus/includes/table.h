/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:43:09 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 15:35:18 by yeepark          ###   ########.fr       */
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
	t_semaphore				sem_message;
	t_data					data;
}	t_table;

int		init_semaphore(t_semaphore *sem, char *name, int value, int *errno);
int		clear_all_semaphore(t_table *table, int number_of_philos, int *errno);
int		clear_semaphore(t_semaphore sem, int *errno);

int		init_table(t_table *table, t_data data, int *errno);
int		init_fork(t_semaphore *fork, t_data data);

void	*run_monitor(void *arg);

#endif
