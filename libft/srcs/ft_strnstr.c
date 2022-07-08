/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:17:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 19:33:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	idx;
	unsigned int	nedlen;

	idx = 0;
	nedlen = ft_strlen(needle);
	if (!needle)
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

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	hay[30] = "12312345123";
//	char	ned[30] = "1234";
//
//	printf("ft : %s\n", ft_strnstr(hay, ned, 20));
//	printf("str : %s\n", strnstr(hay, ned, 20));
//	printf("ft : %s\n", ft_strnstr(hay, ned, 6));
//	printf("str : %s\n", strnstr(hay, ned, 6));
//	printf("ft : %s\n", ft_strnstr(hay, ned, 7));
//	printf("str : %s\n", strnstr(hay, ned, 7));
//}
