/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:35:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/21 23:12:51 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_esc_key(int keycode, t_fractol *frac)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		exit(0);
	}
	return (0);
}

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
	draw_img(frac);
	return (0);
}

int	hook_mouse(int button, int x, int y, t_fractol *frac)
{
	if (button == SCROLL_UP)
		frac->zoom *= 1.2;
	if (button == SCROLL_DOWN)
		frac->zoom /= 1.2;
	draw_img(frac);
	return (0);
}
