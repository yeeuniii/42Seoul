/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:25:24 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/26 22:18:50 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_img(t_fractol *frac)
{
	t_data	img;

	img.img = mlx_new_image(frac->mlx, SIZE_X, SIZE_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.size_line, &img.endian);
	draw_set(frac, &img);
	mlx_put_image_to_window(frac->mlx, frac->win, img.img, 0, 0);
}
