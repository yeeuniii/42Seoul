/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:55 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:19:15 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	idx = 0;
	while (idx < dstsize - dstlen - 1 && src[idx])
	{
		dst[idx + dstlen] = src[idx];
		idx ++;
	}
	dst[idx + dstlen] = 0;
	return (srclen + dstlen);
}
