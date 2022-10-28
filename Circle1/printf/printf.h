#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);

void    handle_type(const char **format, va_list ap, int *cnt);

void    handle_typec(va_list ap, int *cnt);
void    handle_types(va_list ap, int *cnt);
void	handle_typep(va_list ap, int *cnt);
void	handle_typed(va_list ap, int *cnt);
void	handle_typeu(va_list ap, int *cnt);
void	handle_typex_low(va_list ap, int *cnt);
void	handle_typex_up(va_list ap, int *cnt);
void    print_char(char c, int *cnt);
void    print_str(char *s, int *cnt);
void    print_nbr(long n, int *cnt);
void	print_hexa(unsigned int n, char *base, int *cnt);
void	print_memory(uintptr_t n, char *base, int *cnt);

#endif
