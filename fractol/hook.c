/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/24 19:21:37 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_allow_key(int keycode, t_fractol *frac)
{
	if (keycode == LEFT_KEY)
		frac->moved_x -= 0.2;
	if (keycode == RIGHT_KEY)
		frac->moved_x += 0.2;
	if (keycode == DOWN_KEY)
		frac->moved_y -= 0.2;
	if (keycode == UP_KEY)
		frac->moved_y += 0.2;
	return (0);
}

int	hook_number_key(int keycode, t_fractol *frac)
{
	if (keycode == KEY_1)
		frac->color = 0;
	if (keycode == KEY_2)
		frac->color = 1;
	if (keycode == KEY_3)
		frac->color = 2;
	return (0);
}

int	hook_key(int keycode, t_fractol *frac)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		exit(0);
	}
	if (keycode == SPACE_KEY)
	{
		frac->color = 0;
		frac->moved_x = 0;
		frac->moved_y = 0;
		frac->zoom = 1;
	}
	hook_number_key(keycode, frac);
	hook_allow_key(keycode, frac);
	frac->ismouse = 0;
	draw_img(frac);
	return (0);
}

int	hook_mouse(int button, int x, int y, t_fractol *frac)
{
	if (button == SCROLL_UP)
		frac->zoom *= 1.2;
	if (button == SCROLL_DOWN)
		frac->zoom /= 1.2;
	(frac->mouse)[0] = x;
	(frac->mouse)[1] = y;
	frac->ismouse = 1;
	draw_img(frac);
	return (0);
}
