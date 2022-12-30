/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/30 14:26:55 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_died(t_philosopher *philos, t_data data, t_table *table)
{
	int				idx;
	t_philosopher	philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = *(philos + idx);
		pthread_mutex_lock(&philo.mutex_last_time);
		if (philo.last_time_to_eat + data.time_to_die
			<= get_runtime(table->start_time))
		{
			pthread_mutex_unlock(&philo.mutex_last_time);
			pthread_mutex_lock(&table->mutex_end);
			table->is_end = 1; 
			pthread_mutex_unlock(&table->mutex_end);
			return (idx);
		}
		pthread_mutex_unlock(&philo.mutex_last_time);
		idx ++;
	}
	return (0);
}

void	*run_monitor(void *arg)
{
	t_philosopher	*philos;
	t_table			*table;
	t_data			data;
	int				died_philosopher;

	philos = (t_philosopher *)arg;
	table = philos->table;
	data = philos->data;
	died_philosopher = 0;
	while (!died_philosopher)
	{
		died_philosopher = check_died(philos, data, table);
	//	printf("a");
	}
	printf(DIED_MSG, get_runtime(table->start_time), died_philosopher);
	return (0);
}
