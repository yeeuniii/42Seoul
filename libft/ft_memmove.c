/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:47:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 22:13:31 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*tmp;
	unsigned int	idx;

	str = (unsigned char *)dst;
	tmp = (unsigned char *)ft_strdup((char *)src);
	idx = 0;
	while (idx < len)
	{
		str[idx] = tmp[idx];
		idx ++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[30] = "BlockDMask";

	printf("mem: %s\n", memmove(str, str + 2, sizeof(char) * 4));
	printf("mem: %s\n", ft_memmove(str, str + 2, sizeof(char) * 4));
}
