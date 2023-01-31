/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:21:37 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 16:04:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	print_error(int errno)
{
	if (errno == FAIL_ALLOCATION)
		printf("fail allocation\n");
	if (errno == FAIL_THREAD_CREATE)
		printf("fail thread create\n");
	if (errno == FAIL_THREAD_JOIN)
		printf("fail thread join\n");
	if (errno == FAIL_PROCESS_CREATE)
		printf("fail process create\n");
	if (errno == FAIL_SEMAPHORE_OPEN)
		printf("fail semaphore open\n");
	if (errno == FAIL_SEMAPHORE_CLOSE)
		printf("fail semaphore close\n");
	if (errno == FAIL_SEMAPHORE_UNLINK)
		printf("fail semaphore unlink\n");
	exit(1);
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

void	ft_usleep(t_table *table, int goal_time)
{
	int	funtion_calltime;

	funtion_calltime = get_runtime(table->start_time);
	while (get_runtime(table->start_time) - funtion_calltime < goal_time)
		usleep(1000);
}
