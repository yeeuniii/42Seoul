#include "../includes/vector.h"
#include <math.h>
#include <stdio.h>

t_vector	init_vector(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void	set_vector(t_vector *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

double	get_vector_size(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_vector	ft_plus(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vector	ft_minus(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

t_vector	ft_multiple(t_vector vec, double r)
{
	t_vector	new;
	new.x = vec.x * r;
	new.y = vec.y * r;
	new.z = vec.z * r;
	return (new);
}

double	ft_inner_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector	ft_cross_product(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.y * v2.z - v1.z * v2.y;
	new.y = v1.z * v2.x - v1.x * v2.z;
	new.z = v1.x * v2.y - v1.y * v2.x;
	return (new);
}

t_vector ft_unit(t_vector vec)
{
	double	size;

	size = get_vector_size(vec);
	return (ft_multiple(vec, 1 / size));
}
