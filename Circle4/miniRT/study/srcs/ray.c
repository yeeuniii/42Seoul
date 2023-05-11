#include "../includes/minirt.h"
#include <stdio.h>
#include <math.h>

// P(t) = O + Dt where O is origin & D is direct
t_ray	init_ray(t_vector origin, t_vector direct)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direct = direct;
	return (ray);
}

t_point	set_ray_by_t(t_ray ray, double t)
{
	return (ft_plus(ray.origin, ft_multiple(ray.direct, t)));
}

t_vector	get_direct(t_camera camera, double u, double v)
{
	t_vector	vector;

	vector = ft_plus(camera.left_bottom, ft_multiple(camera.horizontal, u));
	vector = ft_plus(vector, ft_multiple(camera.vertical, v));
	vector = ft_minus(vector, camera.origin);
//	printf("x : %f y : %f z : %f\n", vector.x, vector.y, vector.z);
	return (ft_unit(vector));
}

int	hit_sphere(t_sphere sphere, t_ray ray, double *t)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = ft_inner_product(ray.direct, ray.direct);
	b = 2 * ft_inner_product(ray.direct, ft_minus(ray.origin, sphere.center));
	c = ft_inner_product(ft_minus(ray.origin, sphere.center), ft_minus(ray.origin, sphere.center)) - sphere.radius * sphere.radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
		*t = (-b - sqrt(discriminant)) / (2 * a);
	return (discriminant >= 0);
}

t_color	get_color(t_sphere sphere, t_ray ray)
{
	double	t;
	t_color	color;

	if (!hit_sphere(sphere, ray, &t))
		return (init_vector(255, 255, 255));
//	printf("t : %f\n", t);
	color = set_ray_by_t(ray, t);
	color = ft_unit(ft_minus(color, sphere.center));
	color = ft_multiple(ft_plus(color, init_vector(1, 1, 1)), 0.5);
	color = ft_multiple(color, 255.999);
	return (color);	
}
