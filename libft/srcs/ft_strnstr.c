/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:17:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:23:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	idx;
	unsigned int	nedlen;

	idx = 0;
	nedlen = ft_strlen(needle);
	if (!nedlen)
		return ((char *)haystack);
	while (idx <= len - nedlen && haystack[idx])
	{
		if (haystack[idx] == needle[0])
		{
			if (!ft_strncmp(haystack + idx, needle, nedlen))
				return ((char *)(haystack + idx));
		}
		idx ++;
	}
	return (0);
}
