/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:11:53 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:23:29 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;

	idx = ft_strlen(s);
	if (!c)
		return ((char *)(s + idx));
	while (idx)
	{
		idx --;
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
	}
	return (0);
}
