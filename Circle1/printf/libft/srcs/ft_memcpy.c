/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:31:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:18:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (!dst && !src)
		return (0);
	while (idx < n)
	{
		*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
		idx ++;
	}
	return (dst);
}
