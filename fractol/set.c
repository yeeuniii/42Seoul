/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:39:17 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/22 21:54:33 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_fractol frac, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	c;
	t_complex	center;

	i = 0;
	c.re = (((double)x - SIZE / 2) / SIZE * 4 + frac.moved_x) * frac.zoom;
	c.im = ((SIZE / 2 - (double)y) / SIZE * 4 + frac.moved_y) * frac.zoom;
//	c.re = frac.center.re + frac.zoom / 800 * (2 * x - 1 + frac.moved_x);
//	c.im = frac.center.im + frac.zoom / 800 * (2 * y - 1 + frac.moved_y);
//	printf("%f %f\n", c.re, c.im);
//	if (x == 800 && y == 800)
//		printf("center : %f %f\n", frac.center.re, frac.center.im);
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
	z.re = (((double)x - SIZE / 2) / SIZE * 4 + frac.moved_x) * frac.zoom;
	z.im = ((SIZE / 2 - (double)y) / SIZE * 4 + frac.moved_y) * frac.zoom;
	while (i < ITERATION && z.re * z.re + z.im * z.im < 4)
	{
		tmp = z.re * z.re - z.im * z.im + frac.c.re;
		z.im = 2 * z.re * z.im + frac.c.im;
		z.re = tmp;
		i ++;
	}
	return (i);
}

double	modify_to_complex_coordinate(int x, int axis)
{
	if (axis == 0)
		return (((double)x - SIZE / 2) / SIZE * 4);
	if (axis == 1)
		return ((SIZE / 2 - (double)x) / SIZE * 4);
	return (0);
}

unsigned int	set_color(t_fractol frac)
{
	if (frac.color == 0)
		return (BLACK);
	if (frac.color == 1)
		return (PURPLE);
	if (frac.color == 2)
		return (GREEN);
	return (BLACK);
}

void	draw_set(t_fractol *frac, t_data *img)
{
	int		x;
	int		y;
	int		(*func)(t_fractol, int, int);
	unsigned int	color;

	x = 0;
	y = 0;
	if (!ft_strcmp("mandelbrot", frac->set))
		func = is_mandelbrot;
	if (!ft_strcmp("julia", frac->set))
		func = is_julia;
	color = set_color(*frac);
//	(frac->center).re = modify_to_complex_coordinate((frac->mouse)[0], 0) * (1 - frac->zoom);
//	(frac->center).im = modify_to_complex_coordinate((frac->mouse)[1], 1) * (1 - frac->zoom);
//	printf("mouse : %d %d \n", (frac->mouse)[0], (frac->mouse)[1]);
//	printf("adjust : %f %f \n", (frac->center).re, (frac->center).im);
	while (x <= SIZE)
	{
		ft_mlx_pixel_put(img, x, y, color + (func(*frac, x, y) - 1) * 16);
		y ++;
		if (y == SIZE + 1)
		{
			x ++;
			y = 0;
		}
	}
}
