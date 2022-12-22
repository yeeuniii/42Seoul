/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:24:10 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 16:24:19 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	print_error_message(void)
{
	printf("fail allocate\n");
	return (1);
}

int	get_time(struct timeval start_time)
{
	struct timeval	current_time;
	int				difftime;

	gettimeofday(&current_time, NULL);
	difftime = (current_time.tv_sec - start_time.tv_sec) * 1000 + (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (difftime);
}

//void	ft_usleep(int delay_time, int target_time, int start_time)
//{
//	while (target_time < get_time(start_time))
//		usleep(1);
//}
