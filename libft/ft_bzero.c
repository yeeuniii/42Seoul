/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:13:18 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 20:23:38 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bzero(void *s, size_t n)
{
//	char			*str;
//	unsigned int	idx;
	ft_memset(s, 0, n);
//	str = (char *)s;	
//	idx = 0;
//	while (idx < n)
//	{
//		str[idx] = 0;
//		idx ++;
//	}
}

#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char	str[20] = "1234567890";
	char	str1[20] = "1234567890";
	int	idx = -1;

	bzero(str, 2);
	while (++idx < 10)
		printf("%c", str[idx]);
	printf("\n");
	idx = -1;
	bzero(str1, 2);
	while (++idx < 10)
		printf("%c", str1[idx]);
}
