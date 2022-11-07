/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:21 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 19:48:19 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_sandglass(t_stack **a, t_stack **b, int chunk)
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

t_node	*find_highest_ranking_node(t_stack *stack, int ranking, int *reverse)
{
	int		idx;
	int		size;
	t_node	*top_node;
	t_node	*bottom_node;

	idx = 0;
	size = stack->size;
	top_node = stack->head;
	bottom_node = stack->tail;
	while (idx <= size / 2)
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
		idx ++;
	}
	return (0);
}

void	move_to_head(t_stack **stack, t_node *node, int reverse)
{
	void	(*func[2])(t_stack **, char);
	
	func[0] = rotate_stack;
	func[1] = rotate_reverse_stack;
	while ((*stack)->head != node)
		func[reverse](stack, 'b');
}

void	b_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	ranking;
	int	reverse;

	size = (*b)->size;
	ranking = size;
	while (ranking--)
	{
		move_to_head(b, find_highest_ranking_node(*b, ranking, &reverse), reverse);
		push_stack(a, b, 'a');
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	a_size;
	int	chunk;

	a_size = (*a)->size;
	chunk = 0.000000053 * a_size * a_size + 0.3 * a_size + 14.5;
//	chunk = 2;
	make_sandglass(a, b, chunk);
	b_to_a(a, b);
}
