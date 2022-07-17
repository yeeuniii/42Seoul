/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:35:21 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/17 19:09:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		idx;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx ++;
	}
	dest[idx] = 0;
	return (dest);
}
