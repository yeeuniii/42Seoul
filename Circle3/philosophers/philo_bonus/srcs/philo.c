/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:09:12 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/26 13:54:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	print_message(t_philosopher *philo, t_table *table, char *format)
{
	if (is_running(table))
		printf(format, get_runtime(table->start_time), philo->id);
}

void	take_fork(t_table *table)
{
	sem_wait(table->forks.sem);
	sem_wait(table->forks.sem);
}

void	ft_eat(t_philosopher *philo, t_table *table, int time_to_eat)
{
	take_fork(table);
	sem_wait(philo->sem_last_time.sem);
	philo->last_time_to_eat = get_runtime(table->start_time);
	sem_post(philo->sem_last_time.sem);
	print_message(philo, table, EATING_MSG);
	ft_usleep(table, time_to_eat);
	sem_post(table->forks.sem);
	sem_post(table->forks.sem);
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
