/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:46:13 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/26 22:46:52 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c =='x' || c == 'X');
}

void	handle_type(const char **format, va_list ap, int *cnt)
{
	if (**format != '%')
		return ;
	(*format) ++;
	if (!is_type(**format))
		return ;
	if (**format == 'c')
		handle_typec(ap, cnt);
	if (**format == 's')
		handle_types(ap, cnt);
	if (**format == 'p')
		handle_typep(ap, cnt);
	if (**format == 'd' || **format == 'i')
		handle_typed(ap, cnt);
	if (**format == 'u')
		handle_typeu(ap, cnt);
	if (**format == 'x')
		handle_typex_low(ap, cnt);
	if (**format == 'X')
		handle_typex_up(ap, cnt);
	(*format)++;
}
