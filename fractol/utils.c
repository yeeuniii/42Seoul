/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/21 23:12:29 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	perror("usage: ./fractol mandelbrot");
	perror("usage: ./fractol julia [c_real] [c_imaginary]");
	exit(1);
}

