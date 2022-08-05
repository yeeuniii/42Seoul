/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:47:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/08/05 17:43:16 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx ++;
	return (idx);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		idx;
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx ++;
	}
	while (s2[idx - len1])
	{
		str[idx] = s2[idx - len1];
		idx ++;
	}
	str[idx] = 0;
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (idx < dstsize - 1 && src[idx])
	{
		dst[idx] = src[idx];
		idx ++;
	}
	dst[idx] = 0;
	return (ft_strlen(src));
}

char    *ft_strdup(const char *s1)
{
        char    *dest;
        int             idx;

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
