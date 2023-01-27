/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:48:39 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 10:20:56 by yeepark          ###   ########.fr       */
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

static int	handle_error(int is_error, int *errno, t_table *table, int idx)
{
	if (is_error)
	{
		*errno = FAIL_MUTEX_INIT;
		return (destroy_mutex_of_philosopher(table, idx));
	}
	return (0);
}

int	init_philosopher(t_table *table, t_data data, int *errno)
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
		philo->delay = 0;
		philo->data = data;
		philo->table = table;
		set_fork_idx(philo, data.number_of_philos);
		is_error = (pthread_mutex_init(&philo->mutex_eating, 0)
				|| pthread_mutex_init(&philo->mutex_last_time, 0)
				|| pthread_mutex_init(&philo->mutex_delay, 0));
	}
	return (handle_error(is_error, errno, table, idx));
}
