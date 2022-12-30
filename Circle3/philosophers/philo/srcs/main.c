/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:19:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/30 14:24:42 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//void	leaks(void)
//{
//	system("leaks philo");
//}

void	ft_join(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		pthread_join(philo->thread, 0);
		idx ++;
	}
}

void	create_thread(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	pthread_create(&table->monitor, 0, (void *)run_monitor, (void *)table->philos);
	pthread_detach(table->monitor);
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		pthread_create(&philo->thread, 0, (void *)run_philosopher, (void *)philo);
//		pthread_detach(philo->thread);
		idx ++;
	}
	pthread_join(table->monitor, 0);
	ft_join(table, data);
}

void	wait_thread(t_table *table)
{
	while (1)
	{
		pthread_mutex_lock(&table->mutex_end);
		if (table->is_end)
		{
			pthread_mutex_unlock(&table->mutex_end);
			break ;
		}
		pthread_mutex_unlock(&table->mutex_end);
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;
	t_data	data;

//	atexit(leaks);
	if (process_data(argc, argv, &data))
		return (print_usage());
	if (init(&table, data))
		return (print_error_message());
	create_thread(&table, data);
//	wait_thread(&table);
	return (0);
}
