/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:40:24 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/25 10:44:52 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_death(t_philosopher *philo, t_table *table, t_data data)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&philo->mutex_last_time);
	pthread_mutex_lock(&philo->mutex_delay);
	if (philo->last_time_to_eat + data.time_to_die
		< get_runtime(table->start_time) - philo->delay)
	{
		printf("delay : %d, last :%d\n", philo->delay, philo->last_time_to_eat);
		res = 1;
	}
	pthread_mutex_unlock(&philo->mutex_last_time);
	pthread_mutex_unlock(&philo->mutex_delay);
	return (res);
}

void	monitor_death(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		if (is_death(philo, table, data))
		{
			pthread_mutex_lock(&table->mutex_message);
			finish(table);
			printf(DIED_MSG, get_runtime(table->start_time), idx + 1);
			pthread_mutex_unlock(&table->mutex_message);
			return ;
		}
		idx++;
	}
}

void	monitor_eating(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	if (!data.number_of_must_eat || !is_running(table))
		return ;
	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		pthread_mutex_lock(&philo->mutex_eating);
		if (philo->number_of_eating < data.number_of_must_eat)
		{
			pthread_mutex_unlock(&philo->mutex_eating);
			return ;
		}
		pthread_mutex_unlock(&philo->mutex_eating);
		idx++;
	}
	pthread_mutex_lock(&table->mutex_message);
	finish(table);
	printf(EATING_ENOUGH_MSG);
	pthread_mutex_unlock(&table->mutex_message);
}

void	*run_monitor(void *arg)
{
	t_table	*table;
	t_data	data;

	table = (t_table *)arg;
	data = table->philos->data;
	pthread_mutex_lock(&table->mutex_start);
	pthread_mutex_unlock(&table->mutex_start);
	while (is_running(table))
	{
		usleep(100);
		monitor_death(table, data);
		monitor_eating(table, data);
	}
	return (0);
}
