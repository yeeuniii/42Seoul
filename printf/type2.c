#include "printf.h"

void	handle_typed(va_list ap, t_tag tag)
{
	int	d;

	d = va_arg(ap, int);
	
}

void	handle_typex(va_list ap, t_tag tag)
{
	int	x;

	x = va_arg(ap, int);
	print_hexa(x, tag->);
}
