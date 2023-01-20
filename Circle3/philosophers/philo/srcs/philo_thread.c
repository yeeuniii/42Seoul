/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:49 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/20 13:42:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_message(t_philosopher *philo, t_table *table, char *format)
{
	pthread_mutex_lock(&table->mutex_message);
	if (is_ongoing(table))
		printf(format, get_runtime(table->start_time), philo->id);
	pthread_mutex_unlock(&table->mutex_message);
}

void	*run_philo(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;
	t_data			data;

	philo = (t_philosopher *)arg;
	table = philo->table;
	data = philo->data;
	pthread_mutex_lock(&table->mutex_start);
	pthread_mutex_unlock(&table->mutex_start);
	if (philo->id % 2 == 0)
		usleep(50);
	while (is_ongoing(table))
	{
		ft_eat(philo, table, data.time_to_eat);
		ft_sleep(philo, table, data.time_to_sleep);
		ft_think(philo, table);
		if (data.number_of_philos % 2)
			usleep(50);
	}
	return (0);
}
