/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:16:05 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/20 16:03:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	take_fork(t_philosopher *philo, t_table *table)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&table->mutex_fork[philo->right_fork]);
		print_message(philo, table, TAKEN_FORK_MSG);
		pthread_mutex_lock(&table->mutex_fork[philo->left_fork]);
		print_message(philo, table, TAKEN_FORK_MSG);
		return ;
	}
	pthread_mutex_lock(&table->mutex_fork[philo->left_fork]);
	print_message(philo, table, TAKEN_FORK_MSG);
	pthread_mutex_lock(&table->mutex_fork[philo->right_fork]);
	print_message(philo, table, TAKEN_FORK_MSG);
}

void	put_fork(t_philosopher *philo, t_table *table)
{
	if (philo->id % 2)
	{
		pthread_mutex_unlock(&(table->mutex_fork[philo->right_fork]));
		pthread_mutex_unlock(&(table->mutex_fork[philo->left_fork]));
		return ;
	}
	pthread_mutex_unlock(&(table->mutex_fork[philo->left_fork]));
	pthread_mutex_unlock(&(table->mutex_fork[philo->right_fork]));
}

void	ft_eat(t_philosopher *philo, t_table *table, int time_to_eat)
{
	take_fork(philo, table);
	print_message(philo, table, EATING_MSG);
	ft_usleep(table, time_to_eat);
	if (!is_ongoing(table))
	{
		put_fork(philo, table);
		return ;
	}
	pthread_mutex_lock(&philo->mutex_last_time);
	philo->last_time_to_eat = get_runtime(table->start_time);
	pthread_mutex_unlock(&philo->mutex_last_time);
	pthread_mutex_lock(&philo->mutex_eating);
	(philo->number_of_eating)++;
	pthread_mutex_unlock(&philo->mutex_eating);
	put_fork(philo, table);
}

void	ft_sleep(t_philosopher *philo, t_table *table, int time_to_sleep)
{
	print_message(philo, table, SLEEPING_MSG);
	ft_usleep(table, time_to_sleep);
}

void	ft_think(t_philosopher *philo, t_table *table)
{
	print_message(philo, table, THINKING_MSG);
}
