/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:24:10 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/30 13:11:02 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	print_error_message(void)
{
	printf("fail allocate\n");
	return (1);
}

int	get_runtime(struct timeval start_time)
{
	int				runtime;
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	runtime = (current_time.tv_sec - start_time.tv_sec) * 1000;
	runtime += (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (runtime);
}

long	get_uruntime(struct timeval start_time)
{
	long			runtime;
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	runtime = (current_time.tv_sec - start_time.tv_sec) * 1000000;
	runtime += (current_time.tv_usec - start_time.tv_usec);
	return (runtime);
}

void	ft_usleep(t_timeval start_time, int function_call_time, int time_to_do)
{
	while (get_runtime(start_time) < function_call_time + time_to_do)
		usleep(100);
}
