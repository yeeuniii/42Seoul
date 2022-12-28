/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:19:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/28 17:48:53 by yeepark          ###   ########.fr       */
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

int	create_thread(t_table *table, t_data data)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		pthread_create(&philo->thread, 0, (void *)run_philosopher, (void *)philo);
		idx ++;
	}
	pthread_create(&table->monitor, 0, (void *)run_monitor, (void *)table->philos);
	return (1);
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
	ft_join(&table, data);
	return (0);
}
