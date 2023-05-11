#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_rectangle
{
	char		type;
	float		x;
	float		y;
	float		width;
	float		height;
	char		filled_char;
}	t_rectangle;

typedef struct s_data
{
	int					width;
	int					height;
	char				background_char;
	FILE				*file;
	struct s_rectangle	rectangle[4096];
	int					size;
}	t_data;

int ft_strlen(char *str);
int	ft_putstr_fd(char *str, int fd);

#endif
