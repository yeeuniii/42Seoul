/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:47:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 02:36:45 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin_size(char *s1, char *s2, size_t readsize)
{
	size_t	idx;
	size_t	len1;
	char	*str;

	len1 = ft_strlen(s1);
	str = malloc(sizeof(char) * (len1 + readsize + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s1 && s1[idx])
	{
		str[idx] = s1[idx];
		idx ++;
	}
	while (s2 && idx - len1 < readsize)
	{
		str[idx] = s2[idx - len1];
		idx ++;
	}
	str[idx] = 0;
	free(s1);
	s1 = 0;
	return (str);
}

int	ft_free(char *str)
{
	free(str);
	str = 0;
	return (0);
}
