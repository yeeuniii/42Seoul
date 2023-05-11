#ifndef MINIRT_H
# define MINIRT_H

# include "vector.h"

typedef struct s_vector	t_point;
typedef struct s_vector	t_color;
typedef struct s_ray	t_ray;
typedef struct s_camera	t_camera;
typedef struct s_screen	t_screen;
typedef struct s_sphere	t_sphere;

struct s_ray
{
	t_point		origin;
	t_vector	direct;
};

struct s_camera
{
	t_point		origin;
	double		viewport_h; // 뷰포트 세로길이
    double		viewport_w; // 뷰포트 가로길이
    t_vector	horizontal; // 수평길이 벡터
    t_vector	vertical; // 수직길이 벡터
    double		focal_len; // focal length
    t_point		left_bottom; // 왼쪽 아래 코너점
};

struct s_screen
{
	int		width;
	int		height;
	double	ratio; // 종횡비 - aspect_ratio 
};

struct s_sphere
{
	t_vector	center;
	double		radius;
};

t_ray		init_ray(t_vector origin, t_vector direct);
t_screen	init_screen(int width, int height);
t_camera	init_camera(t_screen screen, t_point origin);
t_sphere	init_sphere(t_vector center, double radius);

t_vector	get_direct(t_camera camera, double u, double v);
int			hit_sphere(t_sphere sphere, t_ray ray, double *t);
t_color		get_color(t_sphere sphere, t_ray ray);

#endif
