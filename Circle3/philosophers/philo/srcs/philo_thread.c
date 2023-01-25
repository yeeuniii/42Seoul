/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:34:49 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/25 10:29:59 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_message(t_philosopher *philo, t_table *table, char *format)
{
	pthread_mutex_lock(&table->mutex_message);
	if (is_running(table))
		printf(format, get_runtime(table->start_time), philo->id);
	pthread_mutex_unlock(&table->mutex_message);
}

void	run_one_philo(t_philosopher *philo, t_table *table, t_data data)
{
	if (data.number_of_philos == 1)
	{
		print_message(philo, table, TAKEN_FORK_MSG);
		ft_usleep(table, data.time_to_die);
		finish(table);
	}
}

void	*run_philo(void *arg)
{
	t_philosopher	*philo;
	t_table			*table;
	t_data			data;
	int				delay;

	philo = (t_philosopher *)arg;
	table = philo->table;
	data = philo->data;
	pthread_mutex_lock(&table->mutex_start);
	pthread_mutex_unlock(&table->mutex_start);
	if (philo->id % 2 == 0)
		ft_usleep(table, data.time_to_eat / 2);
	run_one_philo(philo, table, data);
	while (is_running(table))
	{
		delay = 0;
		ft_eat(philo, table, data, &delay);
		ft_sleep(philo, table, data, &delay);
		get_delaytime(philo, data, delay);
		ft_think(philo, table);
	}
	return (0);
}
