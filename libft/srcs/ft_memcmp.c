/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:22:13 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 16:01:46 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	idx;
	unsigned char	*str1;
	unsigned char	*str2;

	idx = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (idx < n)
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		idx ++;
	}
	return (0);
}
