/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:31:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/08 15:25:46 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n)
	{
		*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
		idx ++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[20] = "abcd";
	char	dst1[20] = "abcd";
	char	str[30] = "BlockDMask";
	char	str1[30] = "BlockDMask";
	
	printf("mem : %s\n", memcpy(str, dst, 0));
	printf("ft : %s\n", ft_memcpy(str1, dst1, 0));
}


//
//int	main(void)
//{
//	char	str[30] = "BlockDMask";
//	char	str1[30] = "BlockDMask";
//
//	printf("mem: %s\n", memcpy(str + 2, str, sizeof(char) * 4));
//	printf("ft: %s\n", ft_memcpy(str1 + 2, str1, sizeof(char) * 4));
//}

//
//int	main(void)
//{
//	int	src[10] = {1, 2, 3, 4, 5};
//	int	dest[10];
//	int	dest1[10];
//	int	idx = 0;
//
//	printf("ft\n");
//	while (idx < 10)
//	{
//		printf("%d : %d\n", idx, dest[idx]);
//		idx ++;
//	}
//	ft_memcpy(dest, src, sizeof(int) * 5);
//	printf("\n");
//	idx = 0;
//	while (idx < 10)
//	{
//		printf("%d : %d\n", idx, dest[idx]);
//		idx ++;
//	}
//
//	printf("\nmem\n");
//	idx = 0;
//	while (idx < 10)
//	{
//		printf("%d : %d\n", idx, dest1[idx]);
//		idx ++;
//	}
//	printf("\n");
//	memcpy(dest1, src, sizeof(int) * 5);
//	idx = 0;
//	while (idx < 10)
//	{
//		printf("%d : %d\n", idx, dest1[idx]);
//		idx ++;
//	}
//
//	char src1[30] = "BlockDMask";
//	char dst1[30] = "abcdefghijklmnopqrstuv";
//	char dst2[30] = "abcdefghijklmnopqrstuv";
//
//	printf("ft : %s", ft_memcpy(dst1, src1, sizeof(char) * 11));
//	printf("\tdst: %s\n", dst1);
//	printf("mem: %s", memcpy(dst2, src1, sizeof(char) * 11));
//	printf("\tdst: %s\n", dst2);
//}
