/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:37:25 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 10:16:52 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	handle_error(int *errno, int err_type, t_table *table, t_data data)
{
	*errno = err_type;
	finish(table);
	free_all(table, data.number_of_philos);
}

int	create_thread(t_table *table, t_data data, int *errno)
{
	int				idx;
	int				is_error;
	t_philosopher	*philo;

	idx = 0;
	pthread_mutex_lock(&table->mutex_start);
	is_error = pthread_create(&table->monitor, 0, run_monitor, (void *)table);
	while (!is_error && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		is_error = pthread_create(&philo->thread, 0, run_philo, (void *)philo);
		idx++;
	}
	gettimeofday(&table->start_time, 0);
	pthread_mutex_unlock(&table->mutex_start);
	if (is_error)
		handle_error(errno, FAIL_THREAD_CREATE, table, data);
	return (is_error);
}

int	wait_thread(t_table *table, t_data data, int *errno)
{
	int				idx;
	int				is_error;
	t_philosopher	*philo;

	idx = 0;
	is_error = pthread_join(table->monitor, 0);
	while (!is_error && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		is_error = pthread_join(philo->thread, 0);
		idx++;
	}
	if (is_error)
		handle_error(errno, FAIL_THREAD_JOIN, table, data);
	return (is_error);
}

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
