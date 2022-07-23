/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:46:13 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/22 14:43:35 by yeepark          ###   ########.fr       */
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
	if (!is_type(**format))
		return ;
	if (**format == 'c')
		handle_typec(ap);
	if (**format == 's')
		handle_types(ap);
	if (**format == 'p')
		handle_typep(ap);
	if (**format == 'd' || **format == 'i')
		handle_typed(ap);
	if (**format == 'u')
		handle_typeu(ap);
	if (**format == 'x' || **format == 'X')
		handle_typex(ap, **format);
	(*format) ++;
}
