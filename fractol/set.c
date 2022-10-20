/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:39:17 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/20 22:41:32 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_fractol frac, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	c;

	i = 0;
	c.re = (((double)x - SIZE / 2) / SIZE * 4 + frac.moved_x) * frac.zoom;
	c.im = ((SIZE / 2 - (double)y) / SIZE * 4 + frac.moved_y) * frac.zoom;
	while (i < ITERATION && frac.z.re * frac.z.re + frac.z.im * frac.z.im < 4)
	{
		tmp = frac.z.re * frac.z.re - frac.z.im * frac.z.im + c.re;
		frac.z.im = (2 * frac.z.re * frac.z.im + c.im);
		frac.z.re = tmp;
		i ++;
	}
	return (i);
}

int	is_julia(t_fractol frac, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;

	i = 0;
	z.re = ((double)x - (SIZE / 2)) / SIZE * 4.0 * frac.zoom;
	z.im = ((SIZE / 2) - (double)y) / SIZE * 4.0 * frac.zoom;
	while (i < ITERATION && z.re * z.re + z.im * z.im < 4)
	{
		tmp = z.re * z.re - z.im * z.im + frac.c.re;
		z.im = 2 * z.re * z.im + frac.c.im;
		z.re = tmp;
		i ++;
	}
	return (i);
}

void	draw_set(t_fractol *frac, t_data *img)
{
	int	x;
	int	y;
	int	(*func)(t_fractol, int, int);

	x = 0;
	y = 0;
	if (!ft_strcmp("mandelbrot", frac->set))
		func = is_mandelbrot;
	if (!ft_strcmp("julia", frac->set))
		func = is_julia;
	while (x <= SIZE)
	{
		ft_mlx_pixel_put(img, x, y, 0x00000000 + func(*frac, x, y) * 16);
		y ++;
		if (y == SIZE + 1)
		{
			x ++;
			y = 0;
		}
	}
}
