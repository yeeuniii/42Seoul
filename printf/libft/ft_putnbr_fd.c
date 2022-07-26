/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:46:47 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/11 17:13:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = ((n > 0) - (n < 0));
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10 * sign, fd);
	ft_putchar_fd(n % 10 * sign + '0', fd);
}
