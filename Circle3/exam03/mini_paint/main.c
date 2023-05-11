#include "mini_paint.h"

int	init_data(int argc, char *argv[], t_data *data)
{
	t_circle	*circle;
	int			idx;
	int			num;

	idx = 0;
	if (argc != 2)
		return (ft_putstr_fd("Error: argument\n", 2));
	data->file = fopen(argv[1], "r");
	if (!data->file)
		return (ft_putstr_fd("Error: Operation file corrupted\n", 2));
	if (fscanf(data->file, "%d %d %c\n", &data->width, &data->height, &data->background_char) != 3)
		return (ft_putstr_fd("Error: Operation file corrupted\n", 2));
	if (!(0 < data->width && data->width <= 300) || !(0 < data->height && data->height <= 300))
		return (ft_putstr_fd("Error: Operation file corrupted\n", 2));
	circle = data->circle;
	while ((num = fscanf(data->file, "%c %f %f %f %c\n", &circle->type, &circle->x, &circle->y, &circle->r, &circle->filled_char)) == 5)
	{
		if (!(circle->type == 'c' || circle->type == 'C') || circle->r <= 0)
			return (ft_putstr_fd("Error: Operation file corrupted\n", 2));
	//	printf("%c %f %f %f %c\n", circle->type, circle->x, circle->y, circle->r, circle->filled_char);
		circle = data->circle + (++idx);
	}
	if (num != EOF)
		return (ft_putstr_fd("Error: Operation file corrupted\n", 2));
	data->size = idx;
	return (0);
}

void	init_map(char map[301][301], t_data data)
{
	int	x = -1;
	int	y = -1;

	while (++y < data.height)
	{
		while (++x < data.width)
			map[y][x] = data.background_char;
		map[y][x] = 0;
		x = -1;
	}
}

float	calculate_distance(int x, int y, t_circle circle)
{
	float	dist;

	dist = powf(circle.x - x, 2) + powf(circle.y - y, 2);
	return (sqrtf(dist));
}

int	is_filled(int x, int y, t_circle circle, char map[301][301])
{
	float dist;

	dist = calculate_distance(x, y, circle);
	if (circle.type == 'c')
	{
		if (dist <= circle.r && dist > circle.r - 1)
			return (1);
	}
	if (circle.type == 'C')
	{
		if (dist <= circle.r)
			return (1);
	}
	return (0);
}

void	fill_map(t_data data, t_circle circle, char map[301][301])
{
	int	x = -1;
	int	y = -1;

	while (++y < data.height)
	{
		while (++x < data.width)
		{
			if (is_filled(x, y, circle, map))
				map[y][x] = circle.filled_char;
		}
		x = -1;
	}
}

void	print_map(char map[301][301], int height)
{
	int	idx = -1;

	while (++idx < height)
		printf("%s\n", map[idx]);
}

int	main(int argc, char *argv[])
{	
	t_data	data;
	char	map[301][301];
	int		idx = 0;

	if (init_data(argc, argv, &data))
		return (1);
	init_map(map, data);
//	printf("%d %d %c\n", data.width, data.height, data.background_char);
//	printf("%s\n", map[data.height - 1]);
	while (idx < data.size)
	{
		fill_map(data, data.circle[idx], map);
		idx++;
	}
	print_map(map, data.height);
	fclose(data.file);
	return (0);
}
