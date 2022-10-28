/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:06:26 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/27 16:10:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [3]){b, g, r});
}

int	get_color(int i, t_fractol *frac)
{
	double			t;
	unsigned char	color[3];

	t = (double)i / ITERATION;
	color[0] = (9 * (1 - t) * pow(t, 3) * 255);
	color[1] = (15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color[2] = (8.5 * pow((1 - t), 3) * t * 255);
	return (create_rgb(color[(frac->color) % 3],
			color[(frac->color + 1) % 3], color[(frac->color + 2) % 3]));
}
