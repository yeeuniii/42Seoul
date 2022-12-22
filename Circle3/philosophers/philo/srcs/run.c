/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:40:27 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 14:46:41 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_usleep(int delay_time, int current_time, struct timeval start_time)
{
	while (current_time + delay_time / 1000 > get_time(start_time))
		usleep(1);
}

void	sleep_philosopher(t_table table, t_philosopher *philo)
{
	printf("%d %d is sleeping\n", get_time(table.start_time), philo->number);
	(philo->target_time) += table.data.time_to_sleep;
	ft_usleep(table.data.time_to_sleep, get_time(table.start_time), table.start_time);
}

void	eat_philosopher(t_table table, t_philosopher *philo)
{
	int	time_eating;

	pthread_mutex_lock(&(table.forks_mutex[philo->left_fork]));
	printf("%d %d has taken a fork\n", get_time(table.start_time), philo->number);
	pthread_mutex_lock(&(table.forks_mutex[philo->right_fork]));
	printf("%d %d has taken a fork\n", get_time(table.start_time), philo->number);
	time_eating = get_time(table.start_time);
	printf("%d %d is eating\n", time_eating, philo->number);
	(philo->target_time) += table.data.time_to_eat;
	ft_usleep(table.data.time_to_eat, get_time(table.start_time), table.start_time);
	philo->last_time_to_eat = time_eating;
	(philo->eating_time)++;
	pthread_mutex_unlock(&(table.forks_mutex[philo->left_fork]));
	pthread_mutex_unlock(&(table.forks_mutex[philo->right_fork]));
}

void	think_philosopher(t_table table, t_philosopher *philo)
{
	printf("%d %d is thinking\n", get_time(table.start_time), philo->number);
}

void	run_even_number(t_philosopher *philo)
{
	int	idx = 0;

	if (philo->number % 2)
		usleep(50);
	while (!philo->is_died) //check_die
	{
		usleep(10);
		eat_philosopher(philo->table, philo);
		sleep_philosopher(philo->table, philo);
		think_philosopher(philo->table, philo);
		if (++idx == 5)
			break;
	}
}

void	*run(void *arg)
{
	t_philosopher	*philo;
	
	philo = arg;
	run_even_number(philo);
	return (0);
}
