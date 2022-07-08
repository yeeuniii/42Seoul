/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:14:42 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/08 14:18:06 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n)
	{
		if (*(unsigned char *)(s + idx) == (unsigned char)c)
			return ((void *)(s + idx));
		idx ++;
	}
	return (0);
}

//#include <string.h>
//#include <stdio.h>
//
//int	main(void)
//{
//	char	str[20] = "nice to meet you";
//	char	str1[20] = "nice to meet you";
//
//	printf("ft : %s\n", ft_memchr(str, 'e', 8));
//	printf("mem : %s\n", memchr(str1, 'e', 8));
//	printf("ft : %s\n", ft_memchr(str, 'y', 15));
//	printf("mem : %s\n", memchr(str1, 'y', 15));
//	printf("ft : %s\n", ft_memchr(str, 0, 8));
//	printf("mem : %s\n", memchr(str1, 0, 8));
//}
