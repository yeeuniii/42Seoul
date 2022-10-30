/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:52 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 17:43:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_typed(va_list ap, int *cnt)
{
	int	d;

	d = va_arg(ap, int);
	print_nbr(d, cnt);
}

void	handle_typeu(va_list ap, int *cnt)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	print_nbr(u, cnt);
}

void	handle_typex_low(va_list ap, int *cnt)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (!x)
		print_char('0', cnt);
	print_hexa(x, "0123456789abcdef", cnt);
}

void	handle_typex_up(va_list ap, int *cnt)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (!x)
		print_char('0', cnt);
	print_hexa(x, "0123456789ABCDEF", cnt);
}
