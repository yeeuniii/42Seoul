/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:48:26 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/26 14:11:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	run_philo(t_philosopher *philo, t_table *table, t_data data)
{
	if (philo->id % 2 == 0)
		ft_usleep(table, data.time_to_eat / 2);
	while (is_running(table))
	{
		ft_eat(philo, table, data.time_to_eat);
		ft_sleep(philo, table, data.time_to_sleep);
		ft_think(philo, table);
		printf("%d : end %d\n", philo->id, table->is_end);
	}
	printf("%d process finish\n", philo->id);
	exit(0);
}

int	create_process(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = -1;
	gettimeofday(&table->start_time, 0);
	while (++idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->pid = fork();
//		if (philo->pid == -1)
		if (philo->pid > 0)
			continue ;
		run_philo(philo, table, data);
	}
	pthread_create(&table->monitor, 0, run_monitor, (void *)table);
	pthread_join(table->monitor, 0);
	while (idx--)
		wait(0);
	return (0);
}
