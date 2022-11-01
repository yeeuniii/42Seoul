/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:18:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/02 01:06:21 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_isinteger(char *str)
{
	long	res;
	int		idx;
	int		sign;
	int		digit;

	res = 0;
	idx = 0;
	sign = 1;
	digit = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		sign = (str[idx] == '+') - (str[idx] == '-');
		idx ++;
	}
	while (ft_isdigit(str[idx]) && digit < 11)
	{
		res = res * 10 + str[idx] - '0';
		idx ++;
		digit ++;
	}
	if ((!ft_isdigit(str[idx]) && str[idx]) || digit == 11)
		return (0);
	if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
		return (0);
	return (1);
}

//int	check_duplicated(t_stack)
