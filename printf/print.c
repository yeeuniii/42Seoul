/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:46:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/27 19:30:45 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *cnt)
{
	(*cnt)++;
	write(1, &c, 1);
}

void	print_str(char *s, int *cnt)
{
	if (!s)
		s = "(null)";
	(*cnt) += ft_strlen(s);
	write(1, s, ft_strlen(s));
}

void	print_nbr(long n, int *cnt)
{
	int	sign;

	sign = ((n > 0) - (n < 0));
	if (n < 0)
		print_char('-', cnt);
	if (n > 9 || n < -9)
		print_nbr(n / 10 * sign, cnt);
	print_char(n % 10 * sign + '0', cnt);
}

void	print_hexa(unsigned int n, char *base, int *cnt)
{
	if (n)
	{
		print_hexa(n / 16, base, cnt);
		print_char(base[n % 16], cnt);
	}
}

void	print_memory(uintptr_t n, char *base, int *cnt)
{
	if (n)
	{
		print_memory(n / 16, base, cnt);
		print_char(base[n % 16], cnt);
	}
}
