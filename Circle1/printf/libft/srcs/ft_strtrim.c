/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:25:16 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:19:37 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_set(char const *set, char c)
{
	int	idx;

	idx = 0;
	while (set[idx] != c && set[idx])
		idx ++;
	return (set[idx] == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(set, s1[start]) && s1[start])
		start ++;
	if (start > end)
		return (ft_calloc(1, 1));
	while (is_set(set, s1[end]) && end >= 0)
		end --;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
