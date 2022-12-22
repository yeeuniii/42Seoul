/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:24:10 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 20:29:53 by yeepark          ###   ########.fr       */
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

void	ft_usleep(t_timeval start_time, int function_call_time, int time_to_do)
{
	while (get_runtime(start_time) < function_call_time + time_to_do)
		usleep(1);
}
