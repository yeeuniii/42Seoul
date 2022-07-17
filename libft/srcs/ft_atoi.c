/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/17 18:58:06 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					idx;
	int					sign;

	res = 0;
	idx = 0;
	sign = 1;
	while (ft_isspace(str[idx]))
		idx ++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		sign = (str[idx] == '+') - (str[idx] == '-');
		idx ++;
	}
	while (ft_isdigit(str[idx]))
	{
		res = res * 10 + str[idx] - '0';
		idx ++;
		if (res > 9223372036854775806 && sign == 1)
			return (-1);
		if (res > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)res * sign);
}
