# ifndef OBJECT_H
#define OBJECT_H

typedef struct s_object t_object;
typedef struct s_sphere	t_sphere;

typedef enum
{
	PLANE,
	SPHERE,
	CYLINDER
}	object_type;

struct s_object
{
	object_type	type;
	void		*element;
	t_object	*next;
};

struct s_sphere
{
	t_vector	center;
	double		radius;
	t_vector	color;
};

t_object	init_object();
t_sphere	init_sphere(t_vector center, double radius, t_vector color);


#endif
