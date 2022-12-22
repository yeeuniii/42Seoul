/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:52:12 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 11:59:19 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	join(t_table *table)
{
	int	idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < (table->data).number_of_philos)
	{
		philo = (table->philos) + idx;
		pthread_join(philo->thread, 0);
		idx ++;
	}
}

int	create_thread(t_table *table)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < (table->data).number_of_philos)
	{
		philo = table->philos + idx;
		pthread_create(&(philo->thread), 0, (void *)run, (void *)philo);
		pthread_detach(philo->thread);
		idx ++;
	}
//	pthread_create(&(table->monitor), 0, (void *)run_monitor, (void *)table);
	while (1)
	{}
	return (1);
}
