/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:14:42 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:19:29 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n)
	{
		if (*(unsigned char *)(s + idx) == (unsigned char)c)
			return ((void *)(s + idx));
		idx ++;
	}
	return (0);
}
