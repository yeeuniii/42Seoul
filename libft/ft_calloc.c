/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:56:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 20:14:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*calloc(size_t count, size_t size)
{
	char			*arr;
	unsigned int	idx;

	arr = malloc(size * count);
	ft_bzero(arr, count);
	return ((void *)arr);
}
