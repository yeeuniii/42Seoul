/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/27 00:06:42 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int	main(void)
{
	int d = 1234;
	char c = 'a';
	char *s = "hello";

	printf("\n%d\n", ft_printf("%d%i%c%s%p%x%X%%", d, d, c, s, &d, d, d));
	printf("\n%d\n", printf("%d%i%c%s%p%x%X%%", d, d, c, s, &d, d, d));
//	printf("\n%d\n", ft_printf("abc%d", d));

//	char c = 'a';
//	printf("\n%d\n", ft_printf("%c", c));
//	printf("\n%d\n", ft_printf("%i", d));
//
//	char *s = "abcd";
//	printf("\n%d\n", ft_printf("%s", s));
//
//	unsigned int u = 50;
//	printf("\n%d\n", ft_printf("%u", u));

//	printf("\n%d\n", ft_printf("abc%p", &d));
//	printf("\n%d\n", printf("abc%p", &d));
//
//	printf("\n%d\n", ft_printf("abc%x", d));
//	printf("\n%d\n", printf("abc%x", d));
//	printf("\n%d\n", ft_printf("abc%Xdef", d));
//	printf("\n%d\n", printf("abc%Xdef", d));
		
}


