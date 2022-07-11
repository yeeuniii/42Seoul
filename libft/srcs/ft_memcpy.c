/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:31:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:19:35 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	idx;

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
