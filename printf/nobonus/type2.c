/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:52 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/22 15:05:55 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_typed(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, 1);
}

void	handle_typeu(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	ft_putnbr_fd(u, 1);
}

void	handle_typex(va_list ap, char type)
{
	unsigned int	x;
	char			*base;

	x = va_arg(ap, unsigned int);
	if (type == 'x')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	print_hexa(x, base);
}
