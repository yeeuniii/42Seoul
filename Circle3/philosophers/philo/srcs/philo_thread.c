/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/28 19:45:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_state_message(t_table *table, t_philosopher *philo, char *format)
{
	if (!philo->is_end)
	{
		pthread_mutex_lock(&table->mutex_message);
		printf(format, get_runtime(table->start_time), philo->number);
		pthread_mutex_unlock(&table->mutex_message);
	}
}

void	take_fork(t_table *table, t_philosopher *philo, int fork)
{
	pthread_mutex_lock(&table->mutex_forks[fork]);
	print_state_message(table, philo, TAKEN_FORK_MSG);
}

void	eat_philosopher(t_table *table, t_philosopher *philo, int time_to_eat)
{
	take_fork(table, philo, philo->left_fork);
	take_fork(table, philo, philo->right_fork);
	print_state_message(table, philo, EATING_MSG);
	ft_usleep(table->start_time, get_runtime(table->start_time), time_to_eat);
	philo->last_time_to_eat = get_runtime(table->start_time);
	(philo->eating_time)++;
	pthread_mutex_unlock(&(table->mutex_forks[philo->right_fork]));
	pthread_mutex_unlock(&(table->mutex_forks[philo->left_fork]));
}

void	sleep_philosopher(t_table *table, t_philosopher *philo, int time_to_sleep)
{
	print_state_message(table, philo, SLEEPING_MSG);
	ft_usleep(table->start_time, get_runtime(table->start_time), time_to_sleep);
}

void	think_philosopher(t_table *table, t_philosopher *philo)
{
	print_state_message(table, philo, THINKING_MSG);
}

void	*run_philosopher(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;
	t_data			data;

	philo = (t_philosopher *)arg;
	table = &philo->table;
	data = philo->data;
	if (philo->number % 2 == 0 || philo->number == data.number_of_philos)
		usleep(50);
	while (!philo->is_end)
	{
		eat_philosopher(table, philo, data.time_to_eat);
		sleep_philosopher(table, philo, data.time_to_sleep);
		think_philosopher(table, philo);
	}
	return (0);
}
