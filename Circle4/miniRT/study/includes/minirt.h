#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "vector.h"
# include "object.h"

typedef struct s_vector	t_point;
typedef struct s_vector	t_color;
typedef struct s_ray	t_ray;
typedef struct s_camera	t_camera;
typedef struct s_screen	t_screen;
typedef struct s_light	t_light;

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

struct s_light
{
	t_point	origin;
	t_color	color;
	double	bright_ratio;
};

struct s_screen
{
	int		width;
	int		height;
	double	ratio; // 종횡비 - aspect_ratio 
};

typedef struct s_hitted
{
	t_point		p;
	t_vector	normal;
	double		t_min;
	double		t_max;
	double		t;
	t_color		albedo;
}	t_hitted;

struct  s_scene
{
    t_screen 		screen;
	t_camera        camera;
    t_object        *world;
    t_object        *light;
    t_color         ambient; // 8.4에서 설명할 요소
    t_ray           ray;
    t_hitted	    rec;
};

t_ray		init_ray(t_vector origin, t_vector direct);
t_screen	init_screen(int width, int height);
t_camera	init_camera(t_screen screen, t_point origin);
t_light		init_light(t_point origin, t_color color, double bright_ratio);

t_color		phong_light(t_light light, t_hitted hitted, t_sphere sphere[]);
t_vector	get_direct(t_camera camera, double u, double v);
t_color		get_color(t_sphere sphere[], t_ray ray, t_light light);

int			hit_sphere(t_sphere sphere, t_ray ray, t_hitted *hitted);
int	hit_object(t_sphere sphere[], t_ray ray, t_hitted *hitted);

#endif
