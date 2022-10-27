/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:55 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/27 16:46:03 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "type.h"
# include <stdio.h>
# include <math.h>

# define SIZE_X 600
# define SIZE_Y 600
# define ITERATION 512 

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53
# define SPACE_KEY 49
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20

double	ft_abs(double x);
void	convert_to_complex_coordi(t_fractol *frac, t_complex *c, int x, int y);
void	modify_limit_by_key(t_fractol *frac);
void	modify_limit_by_mouse(t_fractol *frac);

void	ft_mlx_init(t_fractol *frac);
void	initialize_fractol(int argc, char *argv[], t_fractol *frac);
void	initialize_coordinate(t_coordi *coordi, char *set);

void	ft_mlx_pixel_put(t_data *img, int re, int im, int color);
void	draw_img(t_fractol *frac);
int		get_color(int i, t_fractol *frac);
void	draw_set(t_fractol *frac, t_data *img);

int		hook_key(int keycode, t_fractol *frac);
int		hook_allow_key(int keycode, t_fractol *frac);
int		hook_mouse(int button, int x, int y, t_fractol *frac);

#endif
