/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/08 17:01:50 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	idx;

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

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	str[20] = "nice to meet you";
//	char	str1[20] = "nice to meet you";
//
//	printf("ft : %s\n", ft_strchr(str, ' '));
//	printf("chr : %s\n", strchr(str1, ' '));
//	printf("ft : %s\n", ft_strchr(str, 'n'));
//	printf("chr : %s\n", strchr(str1, 'n'));
//	printf("ft : %s\n", ft_strchr(str, 0));
//	printf("chr : %s\n", strchr(str1, 0));
//	printf("ft : %s\n", ft_strchr(str, 'a'));
//	printf("chr : %s\n", strchr(str1, 'a'));
//}
