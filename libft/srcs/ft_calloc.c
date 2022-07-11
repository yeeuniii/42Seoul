/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:56:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:24:25 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;

	arr = malloc(size * count);
	if (!arr)
		return (0);
	ft_bzero(arr, count * size);
	return (arr);
//	return (ft_memset(arr, 0, size * count));
}
