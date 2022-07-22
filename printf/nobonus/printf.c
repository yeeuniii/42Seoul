/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/22 15:32:27 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*res;
	int		cnt;

	res = ft_calloc(ft_strlen(format) + 1, sizeof(char));
	if (!res)
		return (0);
	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			handle_type(&format, ap, res, cnt);
			cnt ++;
		}
		res[cnt] = *format;
		cnt ++;
		format ++;
	}
	ft_putstr_fd(res, 1);
	va_end(ap);
	return (cnt);
}

int	main(void)
{
	char c = 'a';
	char *s = "abcd";
	int	d = 50;
	unsigned int	i = -2147483648;
	unsigned int	num = -50;
	
	ft_printf("character i: %% %c\t string : %s \n", c, s);
	
	ft_printf("%%p : %p\n", &c);
	printf("%%p : %p\n", &c);

	ft_printf("%%d : %d\n", d);
	printf("%%d : %d\n", d);
	ft_printf("%%i : %i\n", i);
	printf("%%i : %i\n", i);
	
	ft_printf("%%u : %u\n", num);
	printf("%%u : %u\n", num);
	ft_printf("%%x : %x\n", num);
	printf("%%x : %x\n", num);
	ft_printf("%%X : %X\n", num);
	printf("%%X : %X\n", num);
}
