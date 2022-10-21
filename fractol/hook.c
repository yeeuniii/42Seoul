/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/20 22:46:50 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_key(int keycode, t_fractol *frac)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		exit(0);
	}
	if (keycode == LEFT_KEY)
	{
		frac->moved_x -= 0.2;
		draw_img(frac);
	}
	if (keycode == RIGHT_KEY)
	{
		frac->moved_x += 0.2;
		draw_img(frac);
	}
	if (keycode == DOWN_KEY)
	{
		frac->moved_y -= 0.2;
		draw_img(frac);
	}
	if (keycode == UP_KEY)
	{
		frac->moved_y += 0.2;
		draw_img(frac);
	}
	return (0);
}

int	hook_mouse(int button, int x, int y, t_fractol *frac)
{
	if (button == SCROLL_UP)
	{
		frac->zoom *= 1.2;
		draw_img(frac);
	}
	if (button == SCROLL_DOWN)
	{
		frac->zoom /= 1.2;
		draw_img(frac);
	}
	return (0);
}
