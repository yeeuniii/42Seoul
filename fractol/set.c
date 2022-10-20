/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:39:17 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/19 22:50:58 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.re = 0;
	z.im = 0;
//	c.re = ((x - SIZE / 2) * 3.0 / SIZE) - 0.5;
//	c.im = ((SIZE / 2) - y) * 2.0 / SIZE;
	c.re = ((double)x - SIZE / 2) / SIZE * 4;
	c.im = (SIZE / 2 - (double)y) / SIZE * 6;
	while (i < ITERATION && pow(z.re, 2) + pow(z.im, 2) < 4)
	{
		tmp = pow(z.re, 2.0) - pow(z.im, 2.0) + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i ++;
	}
	return (i);
}

void	draw_mandelbrot(t_fractol *frac, t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= SIZE)
	{
		is_mandelbrot(x, y);
		ft_mlx_pixel_put(img, x, y, 0x00000000 + is_mandelbrot(x, y) * 16);
		y ++;
		if (y == SIZE + 1)
		{
			x ++;
			y = 0;
		}
	}	
}
