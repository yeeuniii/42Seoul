/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:40:24 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/26 14:27:45 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	monitor_death(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		sem_wait(philo->sem_last_time.sem);
		if (philo->last_time_to_eat + data.time_to_die
			< get_runtime(table->start_time))
		{
			sem_post(philo->sem_last_time.sem);
			finish(table);
			printf(DIED_MSG, get_runtime(table->start_time), idx + 1);
			kill(0, SIGKILL);
			return ;
		}
		sem_post(philo->sem_last_time.sem);
		idx++;
	}
}

//void	monitor_eating(t_table *table, t_data data)
//{
//	int				idx;
//	t_philosopher	*philo;
//
//	if (!data.number_of_must_eat || !is_running(table))
//		return ;
//	idx = 0;
//	while (idx < data.number_of_philos)
//	{
//		philo = table->philos + idx;
//		pthread_mutex_lock(&philo->mutex_eating);
//		if (philo->number_of_eating < data.number_of_must_eat)
//		{
//			pthread_mutex_unlock(&philo->mutex_eating);
//			return ;
//		}
//		pthread_mutex_unlock(&philo->mutex_eating);
//		idx++;
//	}
//	pthread_mutex_lock(&table->mutex_message);
//	finish(table);
//	printf(EATING_ENOUGH_MSG);
//	pthread_mutex_unlock(&table->mutex_message);
//}

void	*run_monitor(void *arg)
{
	t_table	*table;
	t_data	data;

	table = (t_table *)arg;
	data = table->data;
	while (is_running(table))
	{
		usleep(100);
		monitor_death(table, data);
//		monitor_eating(table, data);
	}
	return (0);
}
