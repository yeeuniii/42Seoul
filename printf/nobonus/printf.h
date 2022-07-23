#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void    handle_type(const char **format, va_list ap, int *cnt);

void    handle_typec(va_list ap);
void    handle_types(va_list ap);
void	handle_typep(va_list ap);
void	handle_typed(va_list ap);
void	handle_typeu(va_list ap);
void	handle_typex(va_list ap, char type);

void	print_hexa(unsigned long long n, char *base);
void	print_memory(void	*p);

#endif
