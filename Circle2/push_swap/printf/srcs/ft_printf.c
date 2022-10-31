/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/30 17:42:36 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_type(&format, ap, &cnt);
		}
		else
		{
			print_char(*format, &cnt);
			format ++;
		}
	}
	va_end(ap);
	return (cnt);
}
