/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:02:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 18:18:24 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	get_size(int n)
{
	int	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
		size ++;
	while (n)
	{
		size ++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		idx;
	int		size;
	char	*str;

	idx = 0;
	size = get_size(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		idx = 1;
	}
	str[size] = 0;
	while (idx < size)
	{
		size --;
		str[size] = (n % 10) * ((n > 0) - (n < 0)) + '0';
		n /= 10;
	}
	return (str);
}
