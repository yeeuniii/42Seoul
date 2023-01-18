/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:44:24 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/17 11:06:29 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/data.h"
#include <stdio.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	convert_str_to_int(char *str)
{
	long	res;
	int		idx;

	res = 0;
	idx = 0;
	if (str[idx] == '+')
		idx ++;
	while (is_digit(str[idx]) && idx < 12)
	{
		res *= 10;
		res += str[idx] - '0';
		idx ++;
	}
	if (str[idx] && !is_digit(str[idx]))
		return (-1);
	if (res == 0 || res > 2147483647)
		return (-1);
	return (res);
}

int	print_usage(void)
{
	printf("usage : ./philo number_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]");
	printf(" (But, all argument must be positive integer.)\n");
	return (1);
}

static int	is_valid(t_data data)
{
	return (data.number_of_philos != -1
		&& data.time_to_die != -1
		&& data.time_to_eat != -1
		&& data.time_to_sleep != -1
		&& data.number_of_must_eat != -1);
}

int	init_data(t_data *data, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (1);
	data->number_of_philos = convert_str_to_int(argv[1]);
	data->time_to_die = convert_str_to_int(argv[2]);
	data->time_to_eat = convert_str_to_int(argv[3]);
	data->time_to_sleep = convert_str_to_int(argv[4]);
	data->number_of_must_eat = 0;
	if (argc == 6)
		data->number_of_must_eat = convert_str_to_int(argv[5]);
	return (!is_valid(*data));
}
