#include <stdio.h>
#include <math.h>
#include "../mlx/mlx.h"
#include "../includes/minirt.h"

# define WHITE 0x00FFFFFF
# define BLUE 0x000066CC

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_rgb(t_color color)
{
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_data	image;
	int		width = 300;
	int		height = 400;

	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, width, height, "");
	image.img = mlx_new_image(mlx_ptr, width, height);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, &image.size_line, &image.endian);
	
	t_point		origin = init_vector(0, 0, 0);
	t_screen	screen = init_screen(width, height);
	t_camera	camera = init_camera(screen, origin);
	t_sphere	sphere = init_sphere(init_vector(0, 0, -5), 2);
	t_ray		ray;
	t_color		color;
	int	i = 0;
	int	j = screen.height - 1;
	double	u, v;
	
//	printf("x : %f y : %f z : %f\n", camera.left_bottom.x, camera.left_bottom.y, camera.left_bottom.z);
	while (j >= 0)
	{
		i = 0;
		while (i < screen.width)
		{
			u = (double)i / (screen.width - 1);
			v = (double)j / (screen.height - 1);
			ray = init_ray(origin, get_direct(camera, u, v));
			color = get_color(sphere, ray);
			my_mlx_pixel_put(&image, i, j, get_rgb(color));
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(mlx_ptr, window_ptr, image.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
