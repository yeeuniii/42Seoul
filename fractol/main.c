/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:41:43 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/13 15:27:18 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int set(int argc, char *argv[], t_fractal *frac)
{
	if (ft_strncmp(argv[1], "mandelbrot"))
    {
		frac->set = "mandelbrot";
		(frac->z).re = 0;
		(frac->z).im = 0;
    }
	else if (ft_strncmp(argv[1], "julia") && argc >= 4)
	{
		frac->set = "julia";
		(frac->c).re = ft_atof(argv[2]);
		(frac->c).im = ft_atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "julia"))
	{
		frac->set = "julia";
		(frac->c).re = 0.5;
		(frac->c).im = 0.5;
	}
	else 
		return (0);
	return (1);
}

int	main(int argc, char	*argv[])
{
	t_fractal	frac;
	
	if (!set(argc, argv, &frac))
		ft_error();
}
