/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:37:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/27 16:43:50 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

void	handle_typec(va_list ap, int *cnt);
void	handle_types(va_list ap, int *cnt);
void	handle_typep(va_list ap, int *cnt);
void	handle_typed(va_list ap, int *cnt);
void	handle_typeu(va_list ap, int *cnt);
void	handle_typex_low(va_list ap, int *cnt);
void	handle_typex_up(va_list ap, int *cnt);
void	print_char(char c, int *cnt);
void	print_str(char *s, int *cnt);
void	print_nbr(long n, int *cnt);
void	print_hexa(unsigned int n, char *base, int *cnt);
void	print_memory(uintptr_t n, char *base, int *cnt);

void	handle_type(const char **format, va_list ap, int *cnt);

int		ft_printf(const char *format, ...);

#endif
