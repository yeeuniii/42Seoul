/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/27 16:42:03 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	hook_allow_key(int keycode, t_fractol *frac)
{
	if (keycode == LEFT_KEY)
	{
		frac->allow = 'x';
		frac->moved_x = (frac->coordi).size_re / -3;
	}
	if (keycode == RIGHT_KEY)
	{
		frac->allow = 'x';
		frac->moved_x = (frac->coordi).size_re / 3;
	}	
	if (keycode == DOWN_KEY)
	{
		frac->allow = 'y';
		frac->moved_y = (frac->coordi).size_im / -3;
	}
	if (keycode == UP_KEY)
	{
		frac->allow = 'y';
		frac->moved_y = (frac->coordi).size_im / 3;
	}
	modify_limit_by_key(frac);
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
		initialize_coordinate(&(frac->coordi), frac->set);
	}
	hook_number_key(keycode, frac);
	hook_allow_key(keycode, frac);
	draw_img(frac);
	return (0);
}

int	hook_mouse(int button, int x, int y, t_fractol *frac)
{
	(frac->mouse)[0] = x;
	(frac->mouse)[1] = y;
	if (button == SCROLL_UP)
	{
		frac->zoom = 1.2;
		frac->scroll = SCROLL_UP;
		modify_limit_by_mouse(frac);
	}
	if (button == SCROLL_DOWN)
	{
		frac->zoom = 1 / 1.2;
		frac->scroll = SCROLL_DOWN;
		modify_limit_by_mouse(frac);
	}
	draw_img(frac);
	return (0);
}
