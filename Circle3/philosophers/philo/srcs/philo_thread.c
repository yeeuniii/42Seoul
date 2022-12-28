/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/28 17:13:25 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_table *table, t_philosopher *philo, int fork)
{
	pthread_mutex_lock(&table->mutex_forks[fork]);
	pthread_mutex_lock(&table->mutex_message);
	printf(TAKEN_FORK_MSG, get_runtime(table->start_time), philo->number);
	pthread_mutex_unlock(&table->mutex_message);
}

void	eat_philosopher(t_table *table, t_philosopher *philo, int time_to_eat)
{
	take_fork(table, philo, philo->left_fork);
	take_fork(table, philo, philo->right_fork);
	pthread_mutex_lock(&table->mutex_message);
	printf(EATING_MSG, get_runtime(table->start_time), philo->number);
	pthread_mutex_unlock(&table->mutex_message);
	ft_usleep(table->start_time, get_runtime(table->start_time), time_to_eat);
	philo->last_time_to_eat = get_runtime(table->start_time);
	(philo->eating_time)++;
	pthread_mutex_unlock(&(table->mutex_forks[philo->right_fork]));
	pthread_mutex_unlock(&(table->mutex_forks[philo->left_fork]));
}

void	sleep_philosopher(t_table table, t_philosopher philo, int time_to_sleep)
{
	pthread_mutex_lock(&table.mutex_message);
	printf(SLEEPING_MSG, get_runtime(table.start_time), philo.number);
	pthread_mutex_unlock(&table.mutex_message);
	ft_usleep(table.start_time, get_runtime(table.start_time), time_to_sleep);
}

void	think_philosopher(t_table table, t_philosopher philo)
{
	pthread_mutex_lock(&table.mutex_message);
	printf(THINKING_MSG, get_runtime(table.start_time), philo.number);
	pthread_mutex_unlock(&table.mutex_message);
}

void	*run_philosopher(void *arg)
{
	t_philosopher	*philo;
	t_table			table;
	t_data			data;

	philo = (t_philosopher *)arg;
	table = philo->table;
	data = philo->data;
	if (philo->number % 2 == 0)
		usleep(50);
	while (1)
	{
		eat_philosopher(&table, philo, data.time_to_eat);
		sleep_philosopher(table, *philo, data.time_to_sleep);
		think_philosopher(table, *philo);
	}
	return (0);
}
