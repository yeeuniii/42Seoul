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

t_sphere	init_sphere(t_vector center, double radius)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.radius = radius;
	return (sphere);
}
