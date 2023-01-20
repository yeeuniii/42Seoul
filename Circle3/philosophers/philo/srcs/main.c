/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:14:58 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/20 19:44:31 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	create_thread(t_table *table, t_data data)
{
	int				idx;
	int				is_error;
	t_philosopher	*philo;

	idx = 0;
	is_error = 1;
	if (gettimeofday(&table->start_time, 0))
		return (is_error);
	pthread_mutex_lock(&table->mutex_start);
	is_error = pthread_create(&table->monitor, 0, run_monitor, (void *)table);
	while (!is_error && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		is_error = pthread_create(&philo->thread, 0, run_philo, (void *)philo);
		idx++;
	}
	pthread_mutex_unlock(&table->mutex_start);
	if (is_error)
		finish(table);
	return (is_error);
}

int	wait_thread(t_table *table, t_data data)
{
	int				idx;
	int				is_error;
	t_philosopher	*philo;

	idx = 0;
	is_error = pthread_join(table->monitor, 0);
	while (!is_error && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		is_error = pthread_join(philo->thread, 0);
		idx++;
	}
	if (is_error)
		finish(table);
	return (is_error);
}

//void	leaks(void)
//{
//	system("leaks philo");
//}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_table	table;

//	atexit(leaks);
	if (init_data(&data, argc, argv))
		return (print_usage());
	if (init_table(&table, data) || init_philosopher(&table, data))
		return (printf("error\n"));
	if (create_thread(&table, data) || wait_thread(&table, data))
		return (printf("error\n"));
	free_all(&table, data.number_of_philos);
	return (0);
}
