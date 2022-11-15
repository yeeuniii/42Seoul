/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 02:17:45 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_well_sorted(t_stack stack)
{
	t_node	*node;
	int		prev_number;

	node = stack.head;
	while (node->next)
	{
		prev_number = node->number;
		node = node->next;
		if (prev_number > node->number)
			return (0);
	}
	return (1);
}

void	optimize(t_stack *a, int std)
{
	if (a->tail->ranking <= std)
		rotate_reverse_stack(a, 'a');
	else
		rotate_stack(a, 'a');
}

int	is_ascending_ranking(t_stack stack)
{
	int		idx;
	int		size;
	int		prev_ranking;
	t_node	*node;

	idx = 0;
	size = stack.size;
	node = get_lowest_ranking_node(stack);
	prev_ranking = node->ranking;
	while (idx < size)
	{
		if (prev_ranking > node->ranking)
			return (0);
		prev_ranking = node->ranking;
		node = node->next;
		if (!node)
			node = stack.head;
		idx ++;
	}
	return (1);
}

int	process_head_ranking(t_stack *a, t_stack *b, int *min_idx, int *max_idx)
{
	find_min_and_max_idx(*a, min_idx, max_idx);
	if (!*min_idx)
	{
		push_stack(b, a, 'b');
		sort_size3(a);
		push_stack(a, b, 'a');
		return (1);
	}
	if (!*max_idx)
	{
		push_stack(b, a, 'b');
		sort_size3(a);
		push_stack(a, b, 'a');
		rotate_stack(a, 'a');
		return (1);
	}
	return (0);
}

void	move_from_head(t_stack *a)
{
	t_node	*head;

	head = a->head;
	if (head->ranking == 1)
		swap_stack(a, 'a');
	else if (head->ranking == 2)
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
		swap_stack(a, 'a');
		rotate_reverse_stack(a, 'a');
	}
	else if (head->ranking == 3)
	{
		rotate_reverse_stack(a, 'a');
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else if (head->ranking == 4)
		rotate_stack(a, 'a');
}
