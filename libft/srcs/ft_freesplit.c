/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:21:03 by yeepark          ###   ########.fr       */
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
	while (idx--)
		free(str[idx]);
	free(str);
}

void	*ft_split(char const *s, char c)
{
	int		idx;
	char	*from;
	char	**str;

	idx = 0;
	str = malloc(sizeof(char *) * (count((char *)s, c) + 1));
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
			break ;
		ft_strlcpy(str[idx], from, s - from + 1);
		idx ++;
		while (*s == c)
			s ++;
	}
	str[idx] = 0;
	if (idx < count((char *)s, c))
		ft_free(str, idx);
	return (str);
}

//int	main(void)
//{
//
//	char *string = "      split       this for   me  !       ";
//	char **result = ft_split(string, ' ');
//
//	printf("%s\n", result[0]);
//	printf("%s\n", result[1]);
//	printf("%s\n", result[2]);
//	printf("%s\n", result[3]);
//	printf("%s\n", result[4]);
//	printf("%s\n", result[5]);
//}
