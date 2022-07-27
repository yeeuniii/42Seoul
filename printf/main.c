/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:13:34 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/27 19:33:38 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
//	int d = 1234;
//	char c = 'a';
//	char *s = "hello";
//
//	printf("\n%d\n", ft_printf("%d%i%c%s%p%x%X%%", d, d, c, s, &d, d, d));
//	printf("\n%d\n", printf("%d%i%c%s%p%x%X%%", d, d, c, s, &d, d, d));

//	printf("\n%d\n", ft_printf("%p", 0));
//	printf("\n%d\n", printf("%p", (void *)0));

//	int n=ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX,0, -42);
//	printf("%d\n", n);
//	int m=printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX,0, -42);
//	printf("%d\n", m);

	printf("\n%d\n", ft_printf("%s", NULL));
	printf("\n%d\n", printf("%s", NULL));
}
