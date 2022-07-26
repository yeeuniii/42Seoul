/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/26 22:18:06 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_typec(va_list ap, int *cnt)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	(*cnt)++;
}

void	handle_types(va_list ap, int *cnt)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_putstr_fd(s, 1);
	(*cnt) += ft_strlen(s);
}

void	handle_typep(va_list ap, int *cnt)
{
	uintptr_t	p;

	p = va_arg(ap, uintptr_t);
//	write(1, "0x", 2);
	print_memory(p, "0123456789abcdef", cnt);
}

