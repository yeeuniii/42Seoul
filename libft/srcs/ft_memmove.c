/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:47:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:48:14 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	idx;
	



}

#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str[30] = "BlockDMask";
	char	str1[30] = "BlockDMask";

	printf("mem: %s\n", memmove(str + 2, str, sizeof(char) * 4));
	printf("ft: %s\n", ft_memmove(str1 + 2, str1, sizeof(char) * 4));
}
