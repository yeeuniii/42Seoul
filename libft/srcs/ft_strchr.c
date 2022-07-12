/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 16:35:02 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	if (!c)
		return ((char *)(s + ft_strlen(s)));
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx ++;
	}
	return (0);
}
