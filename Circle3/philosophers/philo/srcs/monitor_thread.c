/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:43:16 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/28 19:49:38 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_die(t_philosopher *philos, t_table table, t_data data)
{
	t_philosopher *philo;
	int	idx;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = philos + idx;
		if (philo->last_time_to_eat + data.time_to_die < get_runtime(table.start_time))
			return (philo->number);
		idx ++;
	}
	return (0);
}

void	set_philo_status(t_philosopher *philos, int number_of_philos)
{
	t_philosopher *philo;
	int	idx;

	idx = 0;
	while (idx < number_of_philos)
	{
		philo = philos + idx;
		philo->is_end = 1;
		idx ++;
	}
}

void	*run_monitor(void *arg)
{
	t_philosopher	*philos;
	t_table			*table;
	t_data			data;
	int				died_philo;

	philos = (t_philosopher *)arg;
	table = &philos->table;
	data = philos->data;
	died_philo = 0;
	while (!died_philo)
		died_philo = check_die(philos, *table, data);
//	table->is_end = 1;
	set_philo_status(philos, data.number_of_philos);
	print_state_message(table, philos + died_philo, DIED_MSG);
	return (0);
}
