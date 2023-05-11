#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector	t_vector;

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

t_vector	init_vector(double x, double y, double z);
void		set_vector(t_vector *vector, double x, double y, double z);
double		get_vector_size(t_vector vec);
t_vector	ft_plus(t_vector v1, t_vector v2);
t_vector	ft_minus(t_vector v1, t_vector v2);
t_vector	ft_multiple(t_vector vec, double r);
double		ft_inner_product(t_vector v1, t_vector v2);
t_vector	ft_cross_product(t_vector v1, t_vector v2);
t_vector 	ft_unit(t_vector vec);

#endif
