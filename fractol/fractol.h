/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:55 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/13 15:12:17 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft/libft.h>
# include <stdio.h>
# include <math.h>

# define SIZE=700
# define ITERATION=100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	char		*set;
	int			color;
	double		limit;
	t_complex	z;
	t_complex	c;

}	t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

#endif
