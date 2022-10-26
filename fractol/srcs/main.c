/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:41:43 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/26 22:19:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_arg(int argc, char *argv[])
{
	if (argc == 1)
		print_usage();
	if (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia")
		&& ft_strcmp(argv[1], "burning ship")
		&& ft_strcmp(argv[1], "burning_ship"))
		print_usage();
}

int	main(int argc, char	*argv[])
{
	t_fractol	frac;

	check_arg(argc, argv);
	initialize_fractol(argc, argv, &frac);
	initialize_coordinate(&(frac.coordi));
	ft_mlx_init(&frac);
	draw_img(&frac);
	mlx_key_hook(frac.win, hook_key, &frac);
	mlx_mouse_hook(frac.win, hook_mouse, &frac);
	mlx_loop(frac.mlx);
}
