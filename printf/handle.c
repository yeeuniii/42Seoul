#include "printf.h"

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '.'
			|| c == '#' || c == ' ' || c == '+');
}

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c =='x' || c == 'X')
}

void	handle_flag(const char **format, va_list ap, t_tag *tag)
{
	if (!is_flag(**format))
		return ;
	tag->flag = **format;
	if (tag->flag == '+')
		handle_type(++format, ap, tag);
	//if (*format == '-')
}

void	handle_type(const char **format, va_list ap, t_tag *tag)
{
	if (!is_type(**format))
		return ;
	tag->type = **format;
	if (tag->type == 'c')
		handle_typec(ap);
	if (tag->type == 's')
		handle_types(ap);
	if (tag->type == 'p')
		handle_typep(ap);
	if (tag->type == 'd' || tag->type == 'i')
		handle_typed(ap, tag);
	if (tag->type == 'u')
		handle_typeu(ap);
	if (tag->type == 'x' || tag->type == 'X')
		handle_typex(ap, tag);
	(*format) ++;
}
