/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:40:27 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/20 15:40:10 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	sleep_philosopher(t_table table, t_philosopher philo)
{
	printf(SLEEPING_MSG, get_time(table.start_time), philo.number);
	usleep(table.data.time_to_sleep);
}

void	eat_philosopher(t_table table, t_philosopher philo)
{
	pthread_mutex_lock(&(table.forks_mutex[philo.left_fork]));
	pthread_mutex_lock(&(table.forks_mutex[philo.right_fork]));
	printf(TAKEN_FORK_MSG, get_time(table.start_time), philo.number);
	printf(TAKEN_FORK_MSG, get_time(table.start_time), philo.number);
	printf(EATING_MSG, get_time(table.start_time), philo.number);
	usleep(table.data.time_to_eat);
	pthread_mutex_unlock(&(table.forks_mutex[philo.left_fork]));
	pthread_mutex_unlock(&(table.forks_mutex[philo.right_fork]));
}

void	think_philosopher(t_table table, t_philosopher philo)
{
	printf(THINKING_MSG, get_time(table.start_time), philo.number);
}

void	run_even_number(t_philosopher *philo)
{
	int	idx = 0;

	while (!philo->is_died) //check_die
	{
		if ((idx + philo->number) % 2)
			sleep_philosopher(philo->table, *philo);
		if (!((idx + philo->number) % 2))
		{
			think_philosopher(philo->table, *philo);
			eat_philosopher(philo->table, *philo);
		}
		idx ++;
		if (idx == 5)
			break;
	}
}

void	*run(void *arg)
{
	t_philosopher	*philo;
	
	philo = arg;
	if ((philo->table).data.number_of_philos % 2)
	{
	//	run_odd_number();
		return (0);
	}
	run_even_number(philo);
	return (0);
}
