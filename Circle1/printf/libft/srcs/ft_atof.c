/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:27:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:15:58 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <math.h>

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static void	calculate(const char **str, double *dst)
{
	(*dst) *= 10;
	(*dst) += **str - '0';
	(*str)++;
}

double	ft_atof(const char *str)
{
	int		sign;
	int		digit;
	double	res;
	double	tmp;

	sign = 1;
	digit = 0;
	tmp = 0;
	res = 0;
	if (ft_issign(*str))
	{
		sign = (*str == '+') - (*str == '-');
		str++;
	}
	while (ft_isdigit(*str) && *str != '.')
		calculate(&str, &res);
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		calculate(&str, &tmp);
		digit--;
	}
	res += tmp * pow(10, digit);
	return (res * sign);
}
