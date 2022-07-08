/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:54:01 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 16:10:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	idx;

	idx = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (idx < dstsize - 1 && src[idx])
	{
		dst[idx] = src[idx];
		idx ++;
	}
	dst[idx] = 0;
	return (ft_strlen(src));
}
//
//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	src[20] = "hello";
//	char	dst1[20] = "nice to meet you";
//	char	dst2[20] = "nice to meet you";
//
//	printf("strlcpy: %ld : %s\n", strlcpy(dst1, src, 10), dst1);
//	printf("ft_strlcpy: %ld : %s\n", ft_strlcpy(dst2, src, 10), dst2);
//}
