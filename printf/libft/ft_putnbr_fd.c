/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:46:47 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/26 21:45:21 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long n, int fd, int *cnt)
{
	long	sign;

	sign = ((n > 0) - (n < 0));
	if (n < 0)
	{
		(*cnt)++;
		ft_putchar_fd('-', fd);
	}
	if (n > 9 || n < -9)
	{
		(*cnt)++;
		ft_putnbr_fd(n / 10 * sign, fd, cnt);
	}
	(*cnt)++;
	ft_putchar_fd(n % 10 * sign + '0', fd);
}
