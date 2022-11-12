/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:13:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 00:13:26 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "numbers.h"
# include "stack.h"
# include "../libft/includes/libft.h"
# include "get_next_line.h"

void test(t_stack **a, t_stack **b);
void print_stack(t_stack *a, t_stack *b);

int		check(char **numbers, int idx);
void	print_error(void);
void	handle_error(int is_error, t_stack **a, t_stack **b, t_numbers *nbrs);
void	print_operation(char *operation_name, char stack_name);

int		process_head_ranking(
		t_stack **a, t_stack **b,
		int *min_idx, int *max_idx);
void	move_from_head(t_stack **a);
void	sort_size3(t_stack **a);

#endif
