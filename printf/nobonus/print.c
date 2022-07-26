/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:46:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/26 21:44:29 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_hexa(unsigned int n, char *base, int *cnt)
{
	if (n)
	{
		(*cnt)++;
		print_hexa(n / 16, base, cnt);
		ft_putchar_fd(base[n % 16], 1);
	}
}

void	print_memory(uintptr_t n, char *base, int *cnt)
{
	if (n)
	{
		(*cnt)++;
		print_memory(n / 16, base, cnt);
		ft_putchar_fd(base[n % 16], 1);
	}
}
