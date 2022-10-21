/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:04:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/19 14:34:14 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
