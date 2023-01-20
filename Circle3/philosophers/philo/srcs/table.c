/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:17:16 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/20 19:49:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	free_table(t_table table)
{
	free(table.philos);
	free(table.forks);
	free(table.mutex_fork);
	return (1);
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

int	init_mutex(t_table *table, t_data data)
{
	int	is_error;
	int	idx;

	idx = -1;
	is_error = 0;
	while (!is_error && ++idx < data.number_of_philos)
		is_error = pthread_mutex_init(table->mutex_fork + idx, 0);
	is_error = (is_error || pthread_mutex_init(&table->mutex_end, 0)
			|| pthread_mutex_init(&table->mutex_start, 0)
			|| pthread_mutex_init(&table->mutex_message, 0));
	if (is_error)
		return (destroy_mutex_of_table(table, idx));
	return (0);
}

int	init_table(t_table *table, t_data data)
{
	int	is_error;

	is_error = 0;
	table->philos = 0;
	table->forks = 0;
	table->mutex_fork = 0;
	table->philos = malloc(sizeof(t_philosopher) * data.number_of_philos);
	if (!table->philos)
		is_error = 1;
	table->forks = malloc(sizeof(char) * data.number_of_philos);
	if (!table->forks)
		is_error = 1;
	table->mutex_fork = malloc(sizeof(pthread_mutex_t) * data.number_of_philos);
	if (!table->mutex_fork)
		is_error = 1;
	if (is_error)
		return (free_table(*table));
	memset(table->forks, 0, sizeof(char) * data.number_of_philos);
	table->is_end = 0;
	return (init_mutex(table, data));
}
