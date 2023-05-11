#include "micro_paint.h"

int	init_data(int argc, char *argv[], t_data *data)
{
	t_rectangle	*rectangle;
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
	rectangle = data->rectangle;
	while ((num = fscanf(data->file, "%c %f %f %f %f %c\n", &rectangle->type, &rectangle->x, &rectangle->y, &rectangle->width, &rectangle->height, &rectangle->filled_char)) == 6)
	{
		if (!(rectangle->type == 'r' || rectangle->type == 'R'))
			return (ft_putstr_fd("Error: Operation file corrupted\n", 2));
		printf("%c %f %f %f %c\n", rectangle->type, rectangle->x, rectangle->y, rectangle->width, rectangle->filled_char);
		rectangle = data->rectangle + (++idx);
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

float	calculate_distance(int x, int y, t_rectangle rectangle)
{
	float	dist;

	dist = powf(rectangle.x - x, 2) + powf(rectangle.y - y, 2);
	return (sqrtf(dist));
}

int	is_filled(int x, int y, t_rectangle rectangle, char map[301][301])
{
	float dist;

	if (rectangle.type == 'r')
	{
		if (((x >= rectangle.x && x < rectangle.x + 1) 
			|| (x <= (rectangle.x + rectangle.width) && x > (rectangle.x + rectangle.width - 1)))
			&& ((y >= rectangle.y && y < rectangle.y + 1) 
			|| (y <= (rectangle.y + rectangle.height) && y > (rectangle.y + rectangle.height - 1))))
			return (1);
	}
	if (rectangle.type == 'R')
	{
		if (x >= rectangle.x && x <= (rectangle.x + rectangle.width)
			&& y >= rectangle.y && y <= (rectangle.y + rectangle.height))
			return (1);
	}
	return (0);
}

void	fill_map(t_data data, t_rectangle rectangle, char map[301][301])
{
	int	x = -1;
	int	y = -1;

	while (++y < data.height)
	{
		while (++x < data.width)
		{
			if (is_filled(x, y, rectangle, map))
				map[y][x] = rectangle.filled_char;
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
		fill_map(data, data.rectangle[idx], map);
		idx++;
	}
	print_map(map, data.height);
	fclose(data.file);
	return (0);
}
