/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:46:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/22 14:58:55 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_hexa(unsigned long long n, char *base)
{
	if (n)
	{
		print_hexa(n / 16, base);
		ft_putchar_fd(base[n % 16], 1);
	}
}

void	print_memory(void	*p)
{
	unsigned long long	addr;

	addr = (unsigned long long)p;
	ft_putstr_fd("0x", 1);
	print_hexa(addr, "0123456789abcdef");
}
