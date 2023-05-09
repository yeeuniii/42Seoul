/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:48:45 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 16:19:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_philosopher *philo, t_table *table)
{
	pthread_mutex_lock(&table->mutex_fork[philo->right_fork]);
	print_message(philo, table, TAKEN_FORK_MSG);
	table->forks[philo->right_fork] = 0;
	pthread_mutex_lock(&table->mutex_fork[philo->left_fork]);
	print_message(philo, table, TAKEN_FORK_MSG);
	table->forks[philo->left_fork] = 0;
}

void	put_fork(t_philosopher *philo, t_table *table)
{
	table->forks[philo->right_fork] = 1;
	pthread_mutex_unlock(&(table->mutex_fork[philo->right_fork]));
	table->forks[philo->left_fork] = 1;
	pthread_mutex_unlock(&(table->mutex_fork[philo->left_fork]));
}

void	ft_eat(t_philosopher *philo, t_table *table, t_data data, int *delay)
{
	take_fork(philo, table);
	print_message(philo, table, EATING_MSG);
	pthread_mutex_lock(&philo->mutex_last_time);
	philo->last_time_to_eat = get_runtime(table->start_time);
	pthread_mutex_unlock(&philo->mutex_last_time);
	*delay -= get_runtime(table->start_time);
	ft_usleep(table, data.time_to_eat);
	pthread_mutex_lock(&philo->mutex_eating);
	(philo->number_of_eating)++;
	pthread_mutex_unlock(&philo->mutex_eating);
	put_fork(philo, table);
}

void	ft_sleep(t_philosopher *philo, t_table *table, t_data data, int *delay)
{
	print_message(philo, table, SLEEPING_MSG);
	ft_usleep(table, data.time_to_sleep);
	*delay += get_runtime(table->start_time);
}

void	ft_think(t_philosopher *philo, t_table *table)
{
	print_message(philo, table, THINKING_MSG);
}
