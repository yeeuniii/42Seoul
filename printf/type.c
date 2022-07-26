/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/27 00:06:22 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_typec(va_list ap, int *cnt)
{
	char	c;

	c = va_arg(ap, int);
	print_char(c, cnt);
}

void	handle_types(va_list ap, int *cnt)
{
	char	*s;

	s = va_arg(ap, char*);
	print_str(s, cnt);
}

void	handle_typep(va_list ap, int *cnt)
{
	uintptr_t	p;

	p = va_arg(ap, uintptr_t);
	print_str("0x", cnt);
	print_memory(p, "0123456789abcdef", cnt);
}

