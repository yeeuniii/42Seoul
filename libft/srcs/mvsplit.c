/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 15:44:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	if (!c)
		return (1);
	while (s[idx])
	{
		idx ++;
		if (s[idx - 1] != c && (s[idx] == c || !s[idx]))
			cnt ++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	int		idx;
	int		size;
	char	*from;
	char	**str;

	idx = 0;
	size = count((char *)s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s == c)
			s ++;
		from = (char *)s;
		while (*s != c && *s)
			s ++;
		str[idx] = malloc(sizeof(char) * (s - from + 1));
		if (!str[idx])
			return (0);
		ft_strlcpy(str[idx], from, s - from + 1);
		idx ++;
	}
	str[size] = 0;
	return (str);
}
