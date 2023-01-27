/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:17:16 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 10:20:29 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_table(t_table table)
{
	free(table.philos);
	free(table.forks);
	free(table.mutex_fork);
}

int	allocate_table(t_table *table, t_data data, int *errno)
{
	table->philos = malloc(sizeof(t_philosopher) * data.number_of_philos);
	table->forks = malloc(sizeof(char) * data.number_of_philos);
	table->mutex_fork = malloc(sizeof(pthread_mutex_t) * data.number_of_philos);
	if (!table->philos || !table->forks || !table->mutex_fork)
	{
		*errno = FAIL_ALLOCATION;
		free_table(*table);
		return (1);
	}
	return (0);
}

int	destroy_mutex_of_table(t_table *table, int idx)
{
	pthread_mutex_destroy(&table->mutex_end);
	pthread_mutex_destroy(&table->mutex_start);
	pthread_mutex_destroy(&table->mutex_message);
	while (idx--)
		pthread_mutex_destroy(table->mutex_fork + idx);
	return (1);
}

int	init_mutex(t_table *table, t_data data, int *errno)
{
	int	idx;
	int	is_error;

	idx = 0;
	is_error = 0;
	while (!is_error && idx < data.number_of_philos)
	{
		is_error = pthread_mutex_init(table->mutex_fork + idx, 0);
		idx++;
	}
	is_error = (is_error
			|| pthread_mutex_init(&table->mutex_end, 0)
			|| pthread_mutex_init(&table->mutex_start, 0)
			|| pthread_mutex_init(&table->mutex_message, 0));
	if (is_error)
	{
		*errno = FAIL_MUTEX_INIT;
		return (destroy_mutex_of_table(table, idx));
	}
	return (0);
}

int	init_table(t_table *table, t_data data, int *errno)
{
	table->philos = 0;
	table->forks = 0;
	table->mutex_fork = 0;
	if (allocate_table(table, data, errno))
		return (1);
	table->is_end = 0;
	memset(table->forks, 1, sizeof(char) * data.number_of_philos);
	return (init_mutex(table, data, errno));
}
