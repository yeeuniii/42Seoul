/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/08 14:21:33 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int	idx;
	int	res;
	int	sign;

	idx = 0;
	res = 0;
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
	}
	return (res * sign);
}

//#include <stdio.h>
//#include <stdlib.h>
//int	main(void)
//{
//	printf("ft : %d\n", ft_atoi(" \t  \n +130"));
//	printf("atoi : %d\n", atoi(" \t  \n +130"));
//	printf("ft : %d\n", ft_atoi("-0"));
//	printf("atoi : %d\n", atoi("-0"));
//	printf("%d\n", ft_atoi("0"));
//	printf("%d\n", ft_atoi("2147483647"));
//	printf("%d\n", ft_atoi("-2147483648"));
//	printf("%d\n", ft_atoi("-214,7483648"));
//	printf("%d\n", ft_atoi("---+214,7483648"));
//	printf("%d\n", ft_atoi("abcde"));
//	printf("\n\n");
//	printf("ft : %d\n", ft_atoi("4294967295"));
//	printf("atoi : %d\n", atoi("4294967295"));
//	printf("ft : %d\n", ft_atoi("42949672"));
//	printf("atoi : %d\n", atoi("42949672"));
//}
