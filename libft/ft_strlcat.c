/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:55 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 17:09:42 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	idx;
	unsigned int	srclen;
	unsigned int	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize - 1)
		return (srclen + dstsize);
	idx = 0;
	while (idx < dstsize - 1 && src[idx])
	{
		dst[idx + dstlen] = src[idx];
		idx ++;
	}
	dst[idx + dstlen] = 0;
	return (srclen + dstlen);
}
//
//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	src[20] = "hello";
//	char	dst[20] = "na";
//	char	src1[20] = "hello";
//	char	dst1[20] = "na";
//
//	printf("str: %lu  %s\n", strlcat(dst, src, 8), dst);
//	printf("ft : %zu  %s\n", ft_strlcat(dst1, src1, 8), dst1);
//}
