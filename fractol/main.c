/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:41:43 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/19 22:49:27 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_arg(int argc, char *argv[], t_fractol *frac)
{
	if (argc == 1)
		return (0);
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
	{
		frac->set = "mandelbrot";
		(frac->z).re = 0;
		(frac->z).im = 0;
		return (1);
	}
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		if (argc >= 4)
		{
			(frac->c).re = atof(argv[2]);
			(frac->c).im = atof(argv[3]);
		}
		frac->set = "julia";
		(frac->c).re = 0.5;
		(frac->c).im = 0.5;
		return (1);
	}
	return (0);
}

int	main(int argc, char	*argv[])
{
	t_fractol	frac;

	if (!check_arg(argc, argv, &frac))
		ft_error();
	if (!ft_mlx_init(&frac))
		perror("Window err");
	draw_img(&frac);
	mlx_loop(frac.mlx);
}
