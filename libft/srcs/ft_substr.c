/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:14:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 15:23:54 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	if (start >= ft_strlen(s))
		return (malloc(1));
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
