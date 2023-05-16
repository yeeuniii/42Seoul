#include "../includes/minirt.h"
#include <stdio.h>

t_vector	get_min_vector(t_vector vec1, t_vector vec2)
{
	t_vector	new;

	new = vec1;
	if (vec1.x > vec2.x)
		new.x = vec2.x;
	if (vec1.y > vec2.y)
		new.y = vec2.y;
	if (vec1.z > vec2.z)
		new.z = vec2.z;
	return (new);
}

void	apply_diffuse(t_color *color, t_light light, t_hitted hitted)
{
	t_color		diffuse;
	t_vector	light_direct;
	double		diffuse_coef;


	light_direct = ft_unit(ft_minus(light.origin, hitted.p));
	diffuse_coef = ft_inner_product(light_direct, hitted.normal);
	if (diffuse_coef < 0)
		diffuse_coef = 0;
	diffuse = ft_multiple(light.color, diffuse_coef);
	*color = ft_plus(*color, diffuse);


}

void	apply_ambient(t_color *color)
{
	t_color	ambient;
	double	ambient_coef;
	
	ambient_coef = 0.1;
	ambient = ft_multiple(init_vector(1, 1, 1), ambient_coef);
	*color = ft_plus(*color, ambient);
}

int	is_shadow(t_sphere sphere[], t_ray light_ray, double light_len)
{
	t_hitted	record;

	record.t_min = 0;
	record.t_max = light_len;
	if (hit_object(sphere, light_ray, &record))
		return (1);
	return (0);
}


t_color	phong_light(t_light light, t_hitted hitted, t_sphere sphere[])
{
	t_color	color;

	t_vector	light_dir;
	double		light_len;
	t_ray		light_ray;
	
	color = init_vector(0, 0, 0);
	apply_diffuse(&color, light, hitted);
	
	light_dir = ft_minus(light.origin, hitted.p);
	light_len = get_vector_size(light_dir);
	light_ray = init_ray(ft_plus(hitted.p, ft_multiple(hitted.normal, 0.000001)), light_dir);
	if (is_shadow(sphere, light_ray, light_len))
		return (init_vector(0, 0, 0));
	
	apply_ambient(&color);
	color.x *= hitted.albedo.x;
	color.y *= hitted.albedo.y;
	color.z *= hitted.albedo.z;
	color = get_min_vector(color, init_vector(1, 1, 1));
//	printf("hitted.albedo : %f %f %f\n", hitted.albedo.x, hitted.albedo.y, hitted.albedo.z);
//	printf("%f %f %f\n", color.x, color.y, color.z);
	return (ft_multiple(color, 255));
}
