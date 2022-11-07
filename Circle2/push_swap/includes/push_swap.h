/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:13:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 17:41:52 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "numbers.h"
# include "stack.h"
# include "../printf/includes/ft_printf.h"
# include "../printf/libft/includes/libft.h"

void test(t_stack **a, t_stack **b);
void print_stack(t_stack *a, t_stack *b);

int		check(char **numbers, int idx);
void	print_error(void);
void	handle_error(int is_error, t_stack **a, t_stack **b, t_numbers *nbrs);

void	sort(t_stack **a, t_stack **b);

#endif
