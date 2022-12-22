/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:12:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 16:44:30 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"

int	print_usage(void)
{
	printf("usage : ./philo number_of_philosophers");
	printf(" time_to_die time_to_eat time_to_sleep");
	printf(" [number_of_times_each_philosopher_must_eat]\n");
	printf("All parameters must be positive integer.\n");
	return (1);
}

int	check_data(t_data data)
{
	return (data.number_of_philos == -1
		|| data.time_to_die == -1
		|| data.time_to_eat == -1
		|| data.time_to_sleep == -1
		|| data.number_of_must_eat == -1);
}

int	process_data(int argc, char *argv[], t_data *data)
{
	if (argc != 5 && argc != 6)
		return (1);
	data->number_of_must_eat = -2;
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_must_eat = ft_atoi(argv[5]);
	return (check_data(*data));
}
