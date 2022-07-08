/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:11:53 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/08 17:02:35 by yeepark          ###   ########.fr       */
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

//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	str[20] = "nice to meet you";
//	char	str1[20] = "nice to meet you";
//
//	printf("ft : %s\n", ft_strrchr(str, ' '));
//	printf("chr : %s\n", strrchr(str1, ' '));
//	printf("ft : %s\n", ft_strrchr(str, 'o'));
//	printf("chr : %s\n", strrchr(str1, 'o'));
//	printf("ft : %s\n", ft_strrchr(str, 0));
//	printf("chr : %s\n", strrchr(str1, 0));
//}
