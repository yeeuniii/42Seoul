/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:44:15 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/29 15:53:31 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

struct	s_philosopher;

typedef struct s_table
{
	struct s_philosopher	*philos;
	pthread_t				monitor;
	struct timeval			start_time;
	char					*forks;
	pthread_mutex_t			*mutex_forks;
	pthread_mutex_t			mutex_message;
	pthread_mutex_t			mutex_end;
	int						is_end;
}	t_table;

int		init_table(t_table *table, int number_of_philos);
int		init_mutex_of_table(t_table *table, int number_of_philos);
int		allocate_table(t_table *table, int number_of_philos);
int		destroy_mutex_of_table(t_table *table, int idx);
void	free_table(t_table table);

#endif
