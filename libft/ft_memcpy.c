/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:31:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 22:30:06 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	idx;
	unsigned char	*str1;
	unsigned char	*str2;

	idx = 0;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (idx < n / sizeof(*src))
	{
		str1[idx] = str2[idx];
		idx ++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	src[10] = {1, 2, 3, 4, 5};
	int	dest[10];
	int	dest1[10];
	int	idx = 0;

	printf("ft\n");
	while (idx < 10)
	{
		printf("%d : %d\n", idx, dest[idx]);
		idx ++;
	}
	ft_memcpy(dest, src, sizeof(int) * 5);
	printf("\n");
	idx = 0;
	while (idx < 10)
	{
		printf("%d : %d\n", idx, dest[idx]);
		idx ++;
	}

	printf("\nmem\n");
	idx = 0;
	while (idx < 10)
	{
		printf("%d : %d\n", idx, dest1[idx]);
		idx ++;
	}
	printf("\n");
	memcpy(dest1, src, sizeof(int) * 5);
	idx = 0;
	while (idx < 10)
	{
		printf("%d : %d\n", idx, dest1[idx]);
		idx ++;
	}

	char src1[30] = "BlockDMask";
	char dst1[30] = "abcdefghijklmnopqrstuv";
	char dst2[30] = "abcdefghijklmnopqrstuv";

	printf("ft : %s", ft_memcpy(dst1, src1, sizeof(char) * 11));
	printf("\tdst: %s\n", dst1);
	printf("mem: %s", memcpy(dst2, src1, sizeof(char) * 11));
	printf("\tdst: %s\n", dst2);
}
