/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:23:43 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/20 13:42:09 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_runtime(struct timeval start_time)
{
	struct timeval	current_time;
	int				time;

	gettimeofday(&current_time, 0);
	time = (current_time.tv_sec - start_time.tv_sec) * 1000;
	time += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (time);
}

void	ft_usleep(t_table *table, int goal_time)
{
	int	funtion_calltime;

	funtion_calltime = get_runtime(table->start_time);
	while (is_ongoing(table))
	{
		if (get_runtime(table->start_time) - funtion_calltime >= goal_time)
			break ;
		usleep(100);
	}
}

int	is_ongoing(t_table *table)
{
	pthread_mutex_lock(&table->mutex_end);
	if (table->is_end)
	{
		pthread_mutex_unlock(&table->mutex_end);
		return (0);
	}
	pthread_mutex_unlock(&table->mutex_end);
	return (1);
}

void	finish(t_table *table)
{
	pthread_mutex_lock(&table->mutex_end);
	table->is_end = 1;
	pthread_mutex_unlock(&table->mutex_end);
}

void	free_all(t_table *table, int number_of_philos)
{
	free_table(*table);
	destroy_mutex_of_table(table, number_of_philos);
	destroy_mutex_of_philosopher(table, number_of_philos);
}
