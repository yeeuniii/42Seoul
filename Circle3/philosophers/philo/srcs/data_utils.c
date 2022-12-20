/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:25:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/16 15:36:10 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_atoi(const char *str)
{
	long	res;
	int		idx;
	int		sign;

	res = 0;
	idx = 0;
	sign = 1;
	if (str[idx] == '+')
		idx++;
	if (!ft_isdigit(str[idx]))
		return (-1);
	while (ft_isdigit(str[idx]))
	{
		res = res * 10 + str[idx] - '0';
		idx ++;
	}
	if (str[idx] && !ft_isdigit(str[idx]))
		return (-1);
	return ((int)res);
}
