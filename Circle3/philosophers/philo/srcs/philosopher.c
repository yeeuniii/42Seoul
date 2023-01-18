/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:16:26 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/18 14:24:39 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	set_fork_idx(t_philosopher *philo, int number_of_philos)
{
	philo->right_fork = philo->id - 2;
	philo->left_fork = philo->id - 1;
	if (philo->id == 1)
		philo->right_fork = number_of_philos - 1;
}

int	destroy_mutex_of_philosopher(t_table *table, int idx)
{
	t_philosopher	*philo;

	while (idx--)
	{
		philo = table->philos + idx;
		pthread_mutex_destroy(&philo->mutex_eating);
		pthread_mutex_destroy(&philo->mutex_last_time);
	}
	return (1);
}

int	init_philosopher(t_table *table, t_data data)
{
	int				idx;
	int				is_error;
	t_philosopher	*philo;

	idx = 0;
	is_error = 0;
	while (!is_error && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->id = ++idx;
		philo->number_of_eating = 0;
		philo->last_time_to_eat = 0;
		philo->data = data;
		philo->table = table;
		set_fork_idx(philo, data.number_of_philos);
		is_error = (pthread_mutex_init(&philo->mutex_eating, 0)
				|| pthread_mutex_init(&philo->mutex_last_time, 0));
	}
	if (is_error)
		return (destroy_mutex_of_philosopher(table, idx));
	return (0);
}
