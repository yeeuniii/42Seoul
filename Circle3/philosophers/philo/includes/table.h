/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:44:15 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/19 21:29:38 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include "philosophers.h"

typedef struct s_table
{
	struct s_data			data;
	struct s_philosopher	*philos;
	pthread_t				monitor;
	struct timeval			start_time;
	pthread_mutex_t			*forks_mutex;
	int						*forks;
}	t_table;

int	init_table(t_table *table);

#endif
