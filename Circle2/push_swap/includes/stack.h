/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:47:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 22:04:42 by yeepark          ###   ########.fr       */
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

t_stack	*make_new_stack(void);
int		init_stack(t_stack **stack, t_numbers *numbers);
void	add_node_front(t_stack **stack, t_node **node);
void	add_node_back(t_stack **stack, t_node **node);
void	clear_stack(t_stack **stack);

t_node	*get_lowest_ranking_node(t_stack *stack);
t_node	*get_highest_ranking_node(t_stack *stack);
void	find_min_and_max_idx(t_stack *stack, int *min_idx, int *max_idx);

void	swap_stack(t_stack **stack, char name);
void	push_stack(t_stack **push_stack, t_stack **pop_stack, char name);
void	rotate_stack(t_stack **stack, char name);
void	rotate_reverse_stack(t_stack **stack, char name);
void	(*get_rotating_function(int reverse))(t_stack **, char);

void	rank(t_stack **stack);

int		check_well_sorted(t_stack *stack);
int		is_ascenging_ranking(t_stack *stack);
void	sort(t_stack **a, t_stack **b);
void	sort_smallsize(int size, t_stack **a, t_stack **b);

#endif
