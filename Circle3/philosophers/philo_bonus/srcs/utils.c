/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:21:37 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 15:22:07 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	print_error(int errno)
{
	if (errno == FAIL_ALLOCATION)
		printf("fail allocation\n");
	if (errno == FAIL_THREAD_CREATE)
		printf("fail thread create\n");
	if (errno == FAIL_THREAD_JOIN)
		printf("fail thread join\n");
	if (errno == FAIL_SEMAPHORE_OPEN)
		printf("fail semaphore open\n");
	if (errno == FAIL_SEMAPHORE_CLOSE)
		printf("fail semaphore close\n");
	if (errno == FAIL_SEMAPHORE_UNLINK)
		printf("fail semaphore unlink\n");
	exit(1);
}

int	is_running(t_table *table)
{
	sem_wait(table->sem_end.sem);
	if (table->is_end)
	{
		sem_post(table->sem_end.sem);
		return (0);
	}
	sem_post(table->sem_end.sem);
	return (1);
}

void	finish(t_table *table)
{
	sem_wait(table->sem_end.sem);
	table->is_end = 1;	
	sem_post(table->sem_end.sem);
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
	while (is_running(table))
	{
		if (get_runtime(table->start_time) - funtion_calltime >= goal_time)
			return ;
		usleep(1000);
	}
	//printf("%d\n",(get_runtime(table->start_time) - funtion_calltime < goal_time));
}
