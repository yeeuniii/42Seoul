/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/24 21:34:36 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	perror("usage: ./fractol mandelbrot");
	perror("usage: ./fractol julia [c_real] [c_imaginary]");
	perror("usage: ./fractol burning_ship or \"burning ship\"");
	exit(1);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	convert_by_mouse_pos(t_fractol *frac, t_complex *c, int x, int y)
{
	double		left;
	double		right;
	double		up;
	double		down;
	t_complex	mouse;
	t_coordi	coordi;

	coordi = frac->coordi;

	mouse.re = coordi.re_min + (frac->mouse)[0] * coordi.size_re / SIZE_X + frac->moved_x;
	left = ft_abs(mouse.re - coordi.re_min);
	right = ft_abs(coordi.re_max - mouse.re);
	coordi.re_min += right * frac->zoom;
	coordi.re_max -= left * frac->zoom;

	mouse.im = coordi.im_max - (frac->mouse)[1] * coordi.size_im / SIZE_Y + frac->moved_y;
	up = ft_abs(coordi.im_max - mouse.im);
	down = ft_abs(mouse.im - coordi.im_min);
	coordi.im_max -= up * frac->zoom;
	coordi.im_min += down * frac->zoom;
	if (!x && !y)
		printf("%f %f\n", mouse.re, mouse.im);
	convert_to_complex_coordi(frac, c, x, y);
	coordi.size_re = ft_abs(coordi.re_max - coordi.re_min);
	c->re = coordi.re_min + x * coordi.size_re / SIZE_X + frac->moved_x;
	c->im = coordi.im_max - y * coordi.size_im / SIZE_Y + frac->moved_y;
}

void	convert_to_complex_coordi(t_fractol *frac, t_complex *c, int x, int y)
{
	t_coordi	*coordi;
	
	coordi = &(frac->coordi);
	coordi->size_re = ft_abs(coordi->re_max - coordi->re_min);
	coordi->size_im = ft_abs(coordi->im_max - coordi->im_min);
	c->re = coordi->re_min + x * coordi->size_re / SIZE_X + frac->moved_x;
	c->im = coordi->im_max - y * coordi->size_im / SIZE_Y + frac->moved_y;
	c->re *= frac->zoom;
	c->im *= frac->zoom;
}

void	modify_coordinate(t_fractol *frac)
{
	t_coordi	*coordi;
	
	coordi = &(frac->coordi);
	coordi->re_max = (coordi->re_min + frac->moved_x) * frac->zoom;
	coordi->re_min = (coordi->re_min + SIZE_X * coordi->size_re / SIZE_X + frac->moved_x) * frac->zoom;
	coordi->im_max = (coordi->im_max + frac->moved_y) * frac->zoom;
	coordi->im_min = (coordi->im_max + SIZE_Y * coordi->size_im / SIZE_Y + frac->moved_y) * frac->zoom;
}
