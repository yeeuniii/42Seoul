/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:54:08 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 16:11:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n - 1 && s1[idx])
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx ++;
	}
	return (s1[idx] - s2[idx]);
}

//#include <string.h>
//#include <stdio.h>
//int	main(void)
//{
//	printf("str: %d \tft_str: %d\n", strncmp("hello", "hella", 4), ft_strncmp("hello", "hella", 4));
//	printf("str: %d \tft_str: %d\n", strncmp("hello", "hella", 5), ft_strncmp("hello", "hella", 5));
//	printf("str: %d \tft_str: %d\n", strncmp("hello", "he", 4), ft_strncmp("hello", "he", 4));
//}
