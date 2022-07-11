/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:54:08 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:23:07 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n - 1 && s1[idx])
	{
		if ((unsigned char)s1[idx] != (unsigned char)s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx ++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
