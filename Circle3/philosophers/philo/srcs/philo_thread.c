/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/30 14:24:27 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_state_message(t_table *table, t_philosopher *philo, char *format)
{
	pthread_mutex_lock(&table->mutex_end);
	if (!table->is_end)
	{
		pthread_mutex_unlock(&table->mutex_end);
		pthread_mutex_lock(&table->mutex_message);
		printf(format, get_runtime(table->start_time), philo->number);
		pthread_mutex_unlock(&table->mutex_message);
	}
	pthread_mutex_unlock(&table->mutex_end);
}

void	take_fork(t_table *table, t_philosopher *philo, int fork)
{
	pthread_mutex_lock(&table->mutex_forks[fork]);
	print_state_message(table, philo, TAKEN_FORK_MSG);
}

void	ft_eat(t_table *table, t_philosopher *philo, int time_to_eat)
{
	take_fork(table, philo, philo->left_fork);
	take_fork(table, philo, philo->right_fork);
	print_state_message(table, philo, EATING_MSG);
	ft_usleep(table->start_time, get_runtime(table->start_time), time_to_eat);
	pthread_mutex_lock(&philo->mutex_last_time);
	philo->last_time_to_eat = get_uruntime(table->start_time);
	pthread_mutex_unlock(&philo->mutex_last_time);
	pthread_mutex_lock(&philo->mutex_eating_time);
	(philo->eating_time)++;
	pthread_mutex_unlock(&philo->mutex_eating_time);
	pthread_mutex_unlock(&(table->mutex_forks[philo->right_fork]));
	pthread_mutex_unlock(&(table->mutex_forks[philo->left_fork]));
}

void	ft_sleep(t_table *table, t_philosopher *philo, int time_to_sleep)
{
	print_state_message(table, philo, SLEEPING_MSG);
	ft_usleep(table->start_time, get_runtime(table->start_time), time_to_sleep);
}

void	ft_think(t_table *table, t_philosopher *philo)
{
	print_state_message(table, philo, THINKING_MSG);
}

void	*run_philosopher(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;
	t_data			data;

	philo = (t_philosopher *)arg;
	table = philo->table;
	data = philo->data;
	if (philo->number % 2 == 0 || philo->number == data.number_of_philos)
		usleep(50);
	pthread_mutex_lock(&table->mutex_end);
	while (!table->is_end)
	{
		pthread_mutex_unlock(&table->mutex_end);
		ft_eat(table, philo, data.time_to_eat);
		ft_sleep(table, philo, data.time_to_sleep);
		ft_think(table, philo);
		pthread_mutex_lock(&table->mutex_end);
	}
	pthread_mutex_unlock(&table->mutex_end);
	return (0);
}
