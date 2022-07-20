#include "printf.h"

void	handle_typec(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
}

void	handle_types(va_list ap)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_putstr_fd(s, 1);
}

void	handle_typep(va_list ap)
{
	void	*p;

	p = va_arg(ap, int);
	print_memory(p);
}


