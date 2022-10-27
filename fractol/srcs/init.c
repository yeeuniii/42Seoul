/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/27 16:44:20 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialize_coordinate(t_coordi *coordi, char *set)
{	
	coordi->re_max = 2;
	coordi->re_min = -2;
	coordi->im_max = 2;
	coordi->im_min = -2;
	if (!ft_strcmp(set, "mandelbrot"))
	{
		coordi->re_max = 1.5;
		coordi->re_min = -2.5;
	}
	coordi->size_re = ft_abs(coordi->re_max - coordi->re_min);
	coordi->size_im = ft_abs(coordi->im_max - coordi->im_min);
}

void	initialize_fractol(int argc, char *argv[], t_fractol *frac)
{
	t_coordi	*coordi;

	coordi = &(frac->coordi);
	frac->set = argv[1];
	if (!ft_strcmp("mandelbrot", frac->set)
		|| !ft_strcmp("burning_ship", frac->set))
	{
		(coordi->z).re = 0;
		(coordi->z).im = 0;
	}
	if (!ft_strcmp("julia", frac->set) && argc >= 4)
	{
		(coordi->c).re = ft_atof(argv[2]);
		(coordi->c).im = ft_atof(argv[3]);
	}
	if (!ft_strcmp("julia", frac->set) && argc < 4)
	{
		(coordi->c).re = -0.8;
		(coordi->c).im = 0.15;
	}
	frac->color = 0;
	frac->moved_x = 0;
	frac->moved_y = 0;
	frac->zoom = 1;
}

void	ft_mlx_init(t_fractol *frac)
{
	int	flag;

	flag = 1;
	frac->mlx = mlx_init();
	if (!frac->mlx)
		flag = 0;
	frac->win = mlx_new_window(frac->mlx, SIZE_X, SIZE_Y, "fractol");
	if (!frac->win)
		flag = 0;
	if (!flag)
	{
		perror("WINDOW ERROR");
		exit(1);
	}
}
