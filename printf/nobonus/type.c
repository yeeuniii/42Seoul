/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/22 15:07:14 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_typec(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
}

void	handle_types(va_list ap)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_putstr_fd(s, 1);
}

void	handle_typep(va_list ap)
{
	void	*p;

	p = va_arg(ap, void *);
	ft_putstr_fd("0x", 1);
	print_hexa((unsigned long long)p, "0123456789abcdef");
}

