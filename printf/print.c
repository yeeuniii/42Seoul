/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:46:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/26 23:03:13 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(char c, int *cnt)
{
	(*cnt) ++;
	write(1, &c, 1);
}

void	print_string(char *s, int *cnt)
{
	(*cnt) += ft_strlen(s);
	write(1, s, ft_strlen(s));
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
