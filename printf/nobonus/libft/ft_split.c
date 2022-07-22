/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/18 14:52:29 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		idx ++;
		if (s[idx - 1] != c && (s[idx] == c || !s[idx]))
			cnt ++;
	}
	return (cnt);
}

static char	**ft_free(char **str, int idx)
{
	while (idx --)
		free(str[idx]);
	free(str);
	return (0);
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
	while (idx < size)
	{
		while (*s == c)
			s ++;
		from = (char *)s;
		while (*s != c && *s)
			s ++;
		str[idx] = malloc(sizeof(char) * (s - from + 1));
		if (!str[idx])
			return (ft_free(str, idx));
		ft_strlcpy(str[idx], from, s - from + 1);
		idx ++;
	}
	str[idx] = 0;
	return (str);
}
