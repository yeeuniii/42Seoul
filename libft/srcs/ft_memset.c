/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/08 11:57:06 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	idx;

	idx = 0;
	while (idx < len)
	{
		*(unsigned char *)(b + idx) = (unsigned char)c;
		idx ++;
	}
	return (b);
}

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	str[20] = "nice to meet you";
//	char	str1[20] = "nice to meet you";
//
//	printf("ft : %s\n", ft_memset(str, 97, 5));
//	printf("mem : %s\n", memset(str1, 97, 5));
//
//	int	arr[20];
//	int	arr1[20];
//	int	idx = 0;
//	memset(arr1, 0, 5*sizeof(int));
//	ft_memset(arr, 0, 5 * sizeof(int));
//	while (idx < 7)
//	{
//		printf("%d : mem %d // ft %d\n", idx, arr1[idx], arr[idx]);
//		idx ++;
//	}
//}
