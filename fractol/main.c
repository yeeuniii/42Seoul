/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:41:43 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/21 21:52:42 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_arg(int argc, char *argv[])
{
	if (((ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia")))
		|| argc == 1)
		print_usage();
}

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
		(frac->c).re = atof(argv[2]);
		(frac->c).im = atof(argv[3]);
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

int	main(int argc, char	*argv[])
{
	t_fractol	frac;

	check_arg(argc, argv);
	initialize_fractol(argc, argv, &frac);
	if (!ft_mlx_init(&frac))
		perror("Window err");
	draw_img(&frac);
	mlx_key_hook(frac.win, hook_key, &frac);
	mlx_mouse_hook(frac.win, hook_mouse, &frac);
	mlx_loop(frac.mlx);
}
