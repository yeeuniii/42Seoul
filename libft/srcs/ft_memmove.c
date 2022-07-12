/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:03:54 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 16:34:12 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	idx = 0;
	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		while (idx < len)
		{
			*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
			idx ++;
		}
	}
	if (dst > src)
	{
		while (len --)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	return (dst);
}
