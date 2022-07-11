/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:26:54 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 16:34:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	unsigned int	size;
	char			*str;

	idx = 0;
	size = ft_strlen(s);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	while (s[idx])
	{
		str[idx] = f(idx, s[idx]);
		idx ++;
	}
	str[idx] = 0;
	return (str);
}
