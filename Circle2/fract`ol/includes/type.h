/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:09:42 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/27 16:29:42 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_coordi
{
	double		re_max;
	double		re_min;
	double		im_max;
	double		im_min;
	double		size_re;
	double		size_im;
	t_complex	z;
	t_complex	c;
}	t_coordi;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	char		*set;
	int			color;
	int			allow;
	int			scroll;
	int			mouse[2];
	double		moved_x;
	double		moved_y;
	double		zoom;
	t_coordi	coordi;
}	t_fractol;

#endif
