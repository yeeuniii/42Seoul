/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/26 23:08:37 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (format)
	{
		handle_type(&format, ap, &cnt);
		if (format)
			break ;
		print_char(*format, &cnt);
		format ++;
	}
	va_end(ap);
	return (cnt);
}

int	main(void)
{
//	int d = 1234;	
//	printf("%d", ft_printf("%d", d));

	char c = 'a';
	int	n = ft_printf("%c", c);
	printf("num : %d", n);

//	char *s = "abcd";
//	printf("%d", ft_printf("%s", s));
}


