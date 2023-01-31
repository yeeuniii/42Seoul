/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:53:28 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 15:39:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	check_death(t_philosopher *philo, t_table *table, int time_to_die, int *status)
{
	sem_wait(philo->sem_last_time.sem);
	if (philo->last_time_to_eat + time_to_die < get_runtime(table->start_time))
	{
		sem_post(philo->sem_last_time.sem);
		sem_wait(table->sem_message.sem);
		printf(DIED_MSG, get_runtime(table->start_time), philo->id);
		*status = IS_DIED;
	}
	sem_post(philo->sem_last_time.sem);
}

void	check_eating_enough(t_philosopher *philo, int number_of_must_eat, int *status)
{
	if (!number_of_must_eat)
		return ;
	sem_wait(philo->sem_eating.sem);
	if (philo->number_of_eating >= number_of_must_eat)
	{
		sem_post(philo->sem_eating.sem);
		*status = IS_ENOUGH;
	}
	sem_post(philo->sem_eating.sem);
}

void	*run_monitor(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;
	t_data			data;
	int				status;

	philo = (t_philosopher *)arg;
	table = philo->table;
	data = philo->data;
	status = IS_RUNNING;
	while (status == IS_RUNNING)
	{
		check_death(philo, table, data.time_to_die, &status);
		check_eating_enough(philo, data.number_of_must_eat, &status);
		usleep(100);
	}
	if (status == IS_DIED)
		exit(1);
	exit(0);
}
