/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 17:09:01 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s != chr && *s)
		s ++;
	return ((char *)s);
}

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	str[20] = "nice to meet you";
//	char	str1[20] = "nice to meet you";
//
//	printf("ft : %s\n", ft_strchr(str, ' '));
//	printf("chr : %s\n", strchr(str1, ' '));
//	printf("ft : %s\n", ft_strchr(str, 'n'));
//	printf("chr : %s\n", strchr(str1, 'n'));
//}
