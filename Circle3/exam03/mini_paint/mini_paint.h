#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_circle
{
	char		type;
	float		x;
	float		y;
	float		r;
	char		filled_char;
}	t_circle;

typedef struct s_data
{
	int				width;
	int				height;
	char			background_char;
	FILE			*file;
	struct s_circle	circle[4096];
	int				size;
}	t_data;

int ft_strlen(char *str);
int	ft_putstr_fd(char *str, int fd);

#endif
