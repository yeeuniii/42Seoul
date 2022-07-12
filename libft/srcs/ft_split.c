/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 16:26:23 by yeepark          ###   ########.fr       */
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

static void	ft_free(char **str, int idx)
{
	while (idx --)
		free(str[idx]);
	free(str);
}

static int	ft_strcopy(char **str, char *s, char c)
{
	int		idx;
	int		size;
	char	*from;

	idx = 0;
	size = count((char *)s, c);
	while (*s)
	{
		while (*s == c)
			s ++;
		from = (char *)s;
		while (*s != c && *s)
			s ++;
		str[idx] = malloc(sizeof(char) * (s - from + 1));
		if (!str[idx])
		{
			ft_free(str, idx);
			return (0);
		}
		ft_strlcpy(str[idx], from, s - from + 1);
		idx ++;
	}
	str[size] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = malloc(sizeof(char *) * (count((char *)s, c) + 1));
	if (!str)
		return (0);
	if (!ft_strcopy(str, (char *)s, c))
		return (0);
	return (str);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char *s = "                  olol";
//	char **result = ft_split(s, ' ');
//
//	printf("%s\n", result[0]);
//	printf("%s\n", result[1]);
//	printf("%s\n", result[2]);
//}
