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
	void	(*handles['x'])(va_list, int *);

	if (!is_type(**format))
		return ;
	handles['c'] = handle_typec;
	handles['s'] = handle_types;
	handles['p'] = handle_typep;
	handles['d'] = handle_typed;
	handles['i'] = handle_typed;
	handles['u'] = handle_typeu;
	handles['x'] = handle_typex_low;
	handles['X'] = handle_typex_up;
	handles[(int)(**format)](ap, cnt);
	(*format) ++;
}
