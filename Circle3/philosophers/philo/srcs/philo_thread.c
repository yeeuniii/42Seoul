/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 21:06:12 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eat_philosopher(t_table *table, t_philosopher *philo, int time_to_eat)
{
	pthread_mutex_lock(&table->mutex_forks[philo->left_fork]);
	printf(TAKEN_FORK_MSG, get_runtime(table->start_time), philo->number);
	pthread_mutex_lock(&(table->mutex_forks[philo->right_fork]));
	printf(TAKEN_FORK_MSG, get_runtime(table->start_time), philo->number);
	printf(EATING_MSG, get_runtime(table->start_time), philo->number);
	philo->last_time_to_eat = get_runtime(table->start_time);
	(philo->eating_time)++;
	ft_usleep(table->start_time, get_runtime(table->start_time), time_to_eat);
	pthread_mutex_unlock(&(table->mutex_forks[philo->left_fork]));
	pthread_mutex_unlock(&(table->mutex_forks[philo->right_fork]));
}

void	sleep_philosopher(t_table table, t_philosopher philo, int time_to_sleep)
{
	printf(SLEEPING_MSG, get_runtime(table.start_time), philo.number);
	ft_usleep(table.start_time, get_runtime(table.start_time), time_to_sleep);
}

void	think_philosopher(t_table table, t_philosopher philo)
{
	printf(THINKING_MSG, get_runtime(table.start_time), philo.number);
}

void	*run_philosopher(void *arg)
{
	t_philosopher	*philo;
	t_table			table;
	t_data			data;

	philo = (t_philosopher *)arg;
	table = philo->table;
	data = philo->data;
	if (philo->number % 2)
		usleep(50);
	while (1)
	{
		eat_philosopher(&table, philo, data.time_to_eat);
		sleep_philosopher(table, *philo, data.time_to_sleep);
		think_philosopher(table, *philo);
	}
}
