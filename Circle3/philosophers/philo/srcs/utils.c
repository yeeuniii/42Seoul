/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:23:43 by yeepark           #+#    #+#             */
/*   Updated: 2023/02/03 12:45:12 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	print_error(int errno)
{
	if (errno == FAIL_ALLOCATION)
		printf("fail allocation\n");
	if (errno == FAIL_MUTEX_INIT)
		printf("fail mutex init\n");
	if (errno == FAIL_THREAD_CREATE)
		printf("fail thread create\n");
	if (errno == FAIL_THREAD_JOIN)
		printf("fail thread join\n");
	return (1);
}

void	free_all(t_table *table, int number_of_philos)
{
	free_table(*table);
	destroy_mutex_of_table(table, number_of_philos);
	destroy_mutex_of_philosopher(table, number_of_philos);
}

void	ft_usleep(t_table *table, int goal_time)
{
	int	funtion_calltime;

	funtion_calltime = get_runtime(table->start_time);
	while (is_running(table)
		&& get_runtime(table->start_time) - funtion_calltime < goal_time)
		usleep(100);
}

int	get_runtime(struct timeval start_time)
{
	struct timeval	current_time;
	int				time;

	gettimeofday(&current_time, 0);
	time = (current_time.tv_sec - start_time.tv_sec) * 1000;
	time += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (time);
}

void	get_delaytime(t_philosopher *philo, t_data data, int delay)
{
	pthread_mutex_lock(&philo->mutex_delay);
	if (delay > data.time_to_eat + data.time_to_sleep)
		philo->delay += delay - (data.time_to_eat + data.time_to_sleep);
	pthread_mutex_unlock(&philo->mutex_delay);
}
