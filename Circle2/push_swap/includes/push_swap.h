/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:13:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 22:01:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "stack.h"
# include "../printf/includes/ft_printf.h"
# include "../printf/libft/includes/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void test(t_stack **a, t_stack **b);

void	print_error(void);
void	handle_error(int is_error, t_stack **a, t_stack **b);

int		check_argument(t_stack *stack, char *str);

#endif
