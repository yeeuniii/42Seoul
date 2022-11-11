/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:21 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 22:05:29 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_from_a_to_b(t_stack **a, t_stack **b, int chunk)
{
	int		idx;
	int		size;
	int		ranking;
	t_node	*head;

	idx = 0;
	size = (*a)->size;
	while (idx < size)
	{
		head = (*a)->head;
		ranking = head->ranking;
		if (ranking < idx)
		{
			push_stack(b, a, 'b');
			idx ++;
		}
		if (idx <= ranking && ranking < idx + chunk)
		{
			push_stack(b, a, 'b');
			rotate_stack(b, 'b');
			idx ++;
		}
		if (ranking >= idx + chunk)
			rotate_stack(a, 'a');
	}
}

t_node	*get_node_matching_ranking(t_stack *stack, int ranking, int *reverse)
{
	int		idx;
	int		size;
	t_node	*top_node;
	t_node	*bottom_node;

	idx = -1;
	size = stack->size;
	top_node = stack->head;
	bottom_node = stack->tail;
	while (++idx <= size / 2)
	{
		if (top_node->ranking == ranking)
		{
			*reverse = 0;
			return (top_node);
		}
		if (bottom_node->ranking == ranking)
		{
			*reverse = 1;
			return (bottom_node);
		}
		top_node = top_node->next;
		bottom_node = bottom_node->prev;
	}
	return (0);
}

void	move_to_head(t_stack **stack, t_node *node, int reverse)
{
	while ((*stack)->head != node)
		(get_rotating_function(reverse))(stack, 'b');
}

void	move_from_b_to_a(t_stack **a, t_stack **b)
{
	int		size;
	int		ranking;
	int		reverse;
	t_node	*node;

	size = (*b)->size;
	ranking = size;
	while (ranking--)
	{
		node = get_node_matching_ranking(*b, ranking, &reverse);
		move_to_head(b, node, reverse);
		push_stack(a, b, 'a');
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int		a_size;
	int		chunk;

	if (check_well_sorted(*a))
		return ;
	a_size = (*a)->size;
	chunk = 0.000000053 * a_size * a_size + 0.3 * a_size + 14.5;
	if (a_size <= 5)
	{
		sort_smallsize(a_size, a, b);
		return ;
	}
//	chunk = 2;
	move_from_a_to_b(a, b, chunk);
	move_from_b_to_a(a, b);
}
