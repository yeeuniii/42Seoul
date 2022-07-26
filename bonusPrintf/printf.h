#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_tag
{
	char	flag;
	char	width;
	char	precision;
	char	type;
}	t_tag;

void    handle_typec(va_list ap);
void    handle_types(va_list ap);
void    handle_flag(const char **format, va_list ap, t_tag *tag);
void    handle_type(const char **format, va_list ap, t_tag *tag);
#endif
