/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/22 17:47:37 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_fractol(int argc, char *argv[], t_fractol *frac)
{
	frac->set = argv[1];
	if (!ft_strcmp("mandelbrot", frac->set))
	{
		(frac->z).re = 0;
		(frac->z).im = 0;
	}
	if (!ft_strcmp("julia", frac->set) && argc >= 4)
	{
		(frac->c).re = ft_atof(argv[2]);
		(frac->c).im = ft_atof(argv[3]);
	}
	if (!ft_strcmp("julia", frac->set) && argc < 4)
	{
		(frac->c).re = -0.8;
		(frac->c).im = 0.15;
	}
	frac->color = 0;
	frac->limit = 2;
	frac->moved_x = 0;
	frac->moved_y = 0;
	frac->zoom = 1;
}

int	ft_mlx_init(t_fractol *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		return (0);
	frac->win = mlx_new_window(frac->mlx, SIZE, SIZE, "fractol");
	if (!frac->win)
		return (0);
	return (1);
}

