/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:40:24 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/18 18:06:09 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_died(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		pthread_mutex_lock(&philo->mutex_last_time);
		if (philo->last_time_to_eat + data.time_to_die
			<= get_runtime(table->start_time))
		{
			pthread_mutex_unlock(&philo->mutex_last_time);
			finish(table);
			table->died_id = idx + 1;
			pthread_mutex_lock(&table->mutex_message);
			printf(DIED_MSG, get_runtime(table->start_time), idx + 1);
			pthread_mutex_unlock(&table->mutex_message);
			return ;
		}
		pthread_mutex_unlock(&philo->mutex_last_time);
		idx++;
	}
}

void	check_eating(t_table *table, t_data data)
{
	int				idx;
	int				is_short;
	t_philosopher	*philo;

	idx = 0;
	is_short = 0;
	if (!data.number_of_must_eat)
		return ;
	while (!is_short && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		pthread_mutex_lock(&philo->mutex_eating);
		if (philo->number_of_eating < data.number_of_must_eat)
			is_short = 1;
	}
	if (!is_short)
	{
		finish(table);
		printf(EATING_ENOUGH_MSG);
	}
}

void	*run_monitor(void *arg)
{
	t_table	*table;
	t_data	data;

	table = (t_table *)arg;
	data = table->philos->data;
	pthread_mutex_lock(&table->mutex_start);
	pthread_mutex_unlock(&table->mutex_start);
	while (is_ongoing(table))
	{
		check_died(table, data);
//		check_eating(table, data);
//		usleep(100);
	}
	return (0);
}
