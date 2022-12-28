/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:05:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/28 16:29:57 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_table(t_table *table, int number_of_philos)
{
	table->is_end = 0;
	if (gettimeofday(&(table->start_time), 0))
		return (1);
	get_runtime(table->start_time);
	return (allocate_table(table, number_of_philos));
}

int	init_mutex(t_table *table, int number_of_philos)
{
	int	idx;
	int	fail_init;

	idx = 0;
	fail_init = 0;
	if (pthread_mutex_init(&table->mutex_message, 0))
		fail_init = 1;
	memset(table->mutex_forks, 0, sizeof(pthread_mutex_t) * number_of_philos);
	while (idx < number_of_philos)
	{
		if (pthread_mutex_init(table->mutex_forks + idx, 0))
			fail_init = 1;
		idx++;
	}
	if (fail_init)
		return (destroy_mutex(table, idx));
	return (0);
}

void	init_philosophers(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->data = data;
		philo->table = *table;
		philo->number = ++idx;
		set_fork(philo);
		philo->last_time_to_eat = 0;
		philo->eating_time = 0;
		philo->is_died = 0;
	}
}

int	init(t_table *table, t_data data)
{
	if (init_table(table, data.number_of_philos))
		return (1);
	init_mutex(table, data.number_of_philos);
	init_philosophers(table, data);
	return (0);
}
