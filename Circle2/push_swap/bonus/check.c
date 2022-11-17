/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:56:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/18 08:55:56 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isinteger(char *str)
{
	long	res;
	int		idx;
	int		sign;

	res = 0;
	idx = 0;
	sign = 1;
	if (ft_issign(str[0]) && ft_strlen(str) == 1)
		return (0);
	if (ft_issign(str[idx]))
	{
		sign = (str[idx] == '+') - (str[idx] == '-');
		idx ++;
	}
	while (ft_isdigit(str[idx]))
	{
		res = res * 10 + str[idx] - '0';
		idx ++;
	}
	if (!ft_isdigit(str[idx]) && str[idx])
		return (0);
	if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
		return (0);
	return (1);
}

int	check_duplicated(char **numbers, int end_idx)
{
	int	start_idx;

	start_idx = 0;
	if (!**(numbers + end_idx))
		return (0);
	while (start_idx < end_idx)
	{
		if (ft_atoi(numbers[start_idx]) == ft_atoi(numbers[end_idx]))
			return (0);
		start_idx ++;
	}
	return (1);
}

int	check_numbers_all(char **numbers, int idx)
{
	return (ft_isinteger(numbers[idx]) && check_duplicated(numbers, idx));
}
