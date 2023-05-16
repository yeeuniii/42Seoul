#include "../includes/minirt.h"

t_screen	init_screen(int width, int height)
{
	t_screen	screen;
	
	screen.width = width;
	screen.height = height;
	screen.ratio = (double)width / height;
	return (screen);
}

t_camera	init_camera(t_screen screen, t_point origin)
{
	t_camera	camera;

	camera.origin = origin;
	camera.viewport_h = 2.0;
	camera.viewport_w = camera.viewport_h * screen.ratio;
	camera.focal_len = 1.0;
	camera.horizontal = init_vector(camera.viewport_w, 0, 0);
	camera.vertical = init_vector(0, camera.viewport_h, 0);
	camera.left_bottom = init_vector(origin.x - camera.viewport_w / 2,
			origin.y - camera.viewport_h / 2, origin.z - camera.focal_len);
	return (camera);
}

t_light		init_light(t_point origin, t_color color, double bright_ratio)
{
	t_light	light;

	light.origin = origin;
	light.color = color;
	light.bright_ratio = bright_ratio;
	return (light);
}

t_sphere	init_sphere(t_vector center, double radius, t_color color)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	sphere.color = ft_multiple(color, 1 / 255.999);
//	printf("%f %f %f\n", sphere.color.x, sphere.color.y, sphere.color.z);
//	printf("%f %f %f\n", color.x, color.y, color.z);
	return (sphere);
}
