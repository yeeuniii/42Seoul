/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:19:46 by yeepark          ###   ########.fr       */
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
