/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:42:55 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/27 16:43:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	convert_to_complex_coordi(t_fractol *frac, t_complex *c, int x, int y)
{
	t_coordi	*coordi;

	coordi = &(frac->coordi);
	coordi->size_re = ft_abs(coordi->re_max - coordi->re_min);
	coordi->size_im = ft_abs(coordi->im_max - coordi->im_min);
	c->re = coordi->re_min + x * coordi->size_re / SIZE_X;
	c->im = coordi->im_max - y * coordi->size_im / SIZE_Y;
}

void	modify_limit_by_key(t_fractol *frac)
{
	t_coordi	*coordi;

	coordi = &(frac->coordi);
	if (frac->allow == 'x')
	{
		coordi->re_max += frac->zoom * frac->moved_x;
		coordi->re_min += frac->zoom * frac->moved_x;
	}
	if (frac->allow == 'y')
	{
		coordi->im_max += frac->zoom * frac->moved_y;
		coordi->im_min += frac->zoom * frac->moved_y;
	}
}

void	modify_limit_by_mouse(t_fractol *frac)
{
	t_coordi	*coordi;
	t_complex	mouse;

	coordi = &(frac->coordi);
	convert_to_complex_coordi(frac, &mouse, (frac->mouse)[0], (frac->mouse)[1]);
	if (frac->scroll == SCROLL_UP)
	{
		coordi->re_min -= ft_abs(mouse.re - coordi->re_min) * frac->zoom;
		coordi->re_max += ft_abs(coordi->re_max - mouse.re) * frac->zoom;
		coordi->im_min -= ft_abs(mouse.im - coordi->im_min) * frac->zoom;
		coordi->im_max += ft_abs(coordi->im_max - mouse.im) * frac->zoom;
	}	
	if (frac->scroll == SCROLL_DOWN)
	{
		coordi->re_min += ft_abs(mouse.re - coordi->re_min) * frac->zoom;
		coordi->re_max -= ft_abs(coordi->re_max - mouse.re) * frac->zoom;
		coordi->im_min += ft_abs(mouse.im - coordi->im_min) * frac->zoom;
		coordi->im_max -= ft_abs(coordi->im_max - mouse.im) * frac->zoom;
	}
}
