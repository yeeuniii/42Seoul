/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:39:17 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/24 21:40:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(t_fractol *frac, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z = (frac->coordi).z;
	convert_to_complex_coordi(frac, &c, x, y);
	while (i < ITERATION && z.re * z.re + z.im * z.im < 4)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = (2 * z.re * z.im + c.im);
		z.re = tmp;
		i ++;
	}
	return (i);
}

int	is_julia(t_fractol *frac, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	c = (frac->coordi).c;
	convert_to_complex_coordi(frac, &z, x, y);
	while (i < ITERATION && z.re * z.re + z.im * z.im < 4)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i ++;
	}
	return (i);
}

int	is_burningship(t_fractol *frac, int x, int y)
{
	int			i;
	double		tmp;
	t_complex	z;
	t_complex	c;

	i = 0;
	z = (frac->coordi).z;
	convert_to_complex_coordi(frac, &c, x, y);
	while (i < ITERATION && z.re * z.re + z.im * z.im < 4)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = (2 * ft_abs(z.re * z.im) + c.im);
		z.re = tmp;
		i ++;
	}
	return (i);
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
	int				x;
	int				y;
	int				(*func)(t_fractol*, int, int);
	unsigned int	color;

	x = 0;
	y = 0;
	if (!ft_strcmp("mandelbrot", frac->set))
		func = is_mandelbrot;
	if (!ft_strcmp("julia", frac->set))
		func = is_julia;
	if (!ft_strcmp("burning ship", frac->set)
		||!ft_strcmp("burning_ship", frac->set))
		func = is_burningship;
	color = set_color(*frac);
	while (x < SIZE_X)
	{
		ft_mlx_pixel_put(img, x, y, color + func(frac, x, y) * 16);
		y ++;
		if (y == SIZE_Y)
		{
			y = 0;
			x ++;
		}
	}
	modify_coordinate(frac);
}
