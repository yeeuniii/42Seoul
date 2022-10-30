/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:17:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:19:32 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	nedlen;

	idx = 0;
	nedlen = ft_strlen(needle);
	if (!nedlen)
		return ((char *)haystack);
	while (idx <= len - nedlen && haystack[idx])
	{
		if (len < nedlen)
			return (0);
		if (haystack[idx] == needle[0])
		{
			if (!ft_strncmp(haystack + idx, needle, nedlen))
				return ((char *)(haystack + idx));
		}
		idx ++;
	}
	return (0);
}
