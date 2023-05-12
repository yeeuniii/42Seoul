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

t_point	point_ray(t_ray ray, double t)
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

int	hit_sphere(t_sphere sphere, t_ray ray, t_hitted *hitted)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	root;

	a = ft_inner_product(ray.direct, ray.direct);
	b = 2 * ft_inner_product(ray.direct, ft_minus(ray.origin, sphere.center));
	c = ft_inner_product(ft_minus(ray.origin, sphere.center), ft_minus(ray.origin, sphere.center)) - sphere.radius * sphere.radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);	
	root = (-b - sqrt(discriminant)) / (2 * a);
	if (root < hitted->t_min || root > hitted->t_max)
	{
		root = (-b + sqrt(discriminant)) / (2 * a);
		if (root < hitted->t_min || root > hitted->t_max)
			return (0);
	}
	hitted->t = root;	
	hitted->p = point_ray(ray, root);
	hitted->normal = ft_unit(ft_minus(hitted->p, sphere.center));
//	hitted->normal = ft_multiple(ft_minus(hitted->p, sphere.center), 1 / sphere.radius);
	return (1);
}

t_color	get_color(t_sphere sphere, t_ray ray)
{
	t_hitted	hitted;
	t_color		color;
	
	hitted.t_min = 0;
	hitted.t_max = INFINITY;
	if (!hit_sphere(sphere, ray, &hitted))
		return (init_vector(255, 255, 255));
	if (ft_inner_product(ray.origin, hitted.normal) > 0)
		hitted.normal = ft_multiple(hitted.normal, -1);
	color = ft_multiple(ft_plus(hitted.normal, init_vector(1, 1, 1)), 0.5);
	return (ft_multiple(color, 255.999));	
}
