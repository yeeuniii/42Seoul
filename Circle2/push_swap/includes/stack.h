/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:47:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 02:20:46 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "node.h"

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	init_stack(t_stack *stack);
int		init_a_stack(t_stack *a, t_numbers *numbers);
void	add_node_front(t_stack *stack, t_node **node);
void	add_node_back(t_stack *stack, t_node **node);
void	clear_stack(t_stack *stack);

t_node	*get_lowest_ranking_node(t_stack stack);
t_node	*get_highest_ranking_node(t_stack stack);
void	find_min_and_max_idx(t_stack stack, int *min_idx, int *max_idx);

void	swap(t_stack *stack);
void	push(t_stack *push_stack, t_stack *pop_stack);
void	rotate(t_stack *stack);
void	rotate_reverse(t_stack *stack);
void	swap_stack(t_stack *stack, char name);
void	push_stack(t_stack *push_stack, t_stack *pop_stack, char name);
void	rotate_stack(t_stack *stack, char name);
void	rotate_reverse_stack(t_stack *stack, char name);
void	swap_both(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b);
void	rotate_reverse_both(t_stack *a, t_stack *b);

void	(*get_rotating_function(int reverse))(t_stack *, char);
void	(*get_single_operation_function(char *input))(t_stack *, char);
void	(*get_both_operation_function(char *input))(t_stack *, t_stack *);

void	rank(t_stack *stack);

void	sort(t_stack *a, t_stack *b);
int		check_well_sorted(t_stack stack);
int		is_ascending_ranking(t_stack stack);
void	optimize(t_stack *a, int std);

void	sort_smallsize(int size, t_stack *a, t_stack *b);
int		process_head_ranking(t_stack *a, t_stack *b, int *min, int *max);
void	move_from_head(t_stack *a);
void	sort_size3(t_stack *a);
void	sort_by_standard_input(t_stack *a, t_stack *b);
void	print_well_sorted(t_stack a, t_stack b);

#endif
