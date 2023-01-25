/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:23:43 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/25 10:46:31 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_running(t_table *table)
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

void	ft_usleep(t_table *table, int goal_time)
{
	int	funtion_calltime;

	funtion_calltime = get_runtime(table->start_time);
	while (is_running(table))
	{
		if (get_runtime(table->start_time) - funtion_calltime >= goal_time)
			break ;
		usleep(100);
	}
}

int	get_runtime(struct timeval start_time)
{
	struct timeval	current_time;
	int				time;

	gettimeofday(&current_time, 0);
	time = (current_time.tv_sec - start_time.tv_sec) * 1000;
	time += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (time);
}

void	get_delaytime(t_philosopher *philo, t_data data, int delay)
{
	pthread_mutex_lock(&philo->mutex_delay);
	if (delay > data.time_to_eat + data.time_to_sleep)
		philo->delay += delay - (data.time_to_eat + data.time_to_sleep);
	pthread_mutex_unlock(&philo->mutex_delay);
}
