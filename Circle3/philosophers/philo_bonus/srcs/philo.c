/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:09:12 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 15:25:10 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	print_message(t_philosopher *philo, t_table *table, char *format)
{
	sem_wait(table->sem_message.sem);
	printf(format, get_runtime(table->start_time), philo->id);
	sem_post(table->sem_message.sem);
}

void	take_fork(t_philosopher *philo, t_table *table)
{
	sem_wait(table->forks.sem);
	print_message(philo, table, TAKEN_FORK_MSG);
	sem_wait(table->forks.sem);
	print_message(philo, table, TAKEN_FORK_MSG);
}

void	ft_eat(t_philosopher *philo, t_table *table, int time_to_eat)
{
	take_fork(philo, table);
	print_message(philo, table, EATING_MSG);
	sem_wait(philo->sem_last_time.sem);
	philo->last_time_to_eat = get_runtime(table->start_time);
//	printf("%d last : %d\n", philo->id, philo->last_time_to_eat);
	sem_post(philo->sem_last_time.sem);
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
