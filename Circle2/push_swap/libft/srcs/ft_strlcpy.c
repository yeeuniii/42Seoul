/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:54:01 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:19:18 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

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
