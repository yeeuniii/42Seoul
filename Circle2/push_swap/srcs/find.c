/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:29:01 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 18:19:08 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_lowest_ranking_node(t_stack *stack)
{
	t_node	*node;
	t_node	*min_node;

	node = stack->head;
	min_node = node;
	while (node)
	{
		if (min_node->ranking > node->ranking)
			min_node = node;
		node = node->next;	
	}
	return (min_node);
}

t_node	*get_highest_ranking_node(t_stack *stack)
{
	t_node	*node;
	t_node	*max_node;

	node = stack->head;
	max_node = node;
	while (node)
	{
		if (max_node->ranking < node->ranking)
			max_node = node;
		node = node->next;	
	}
	return (max_node);
}

void	find_min_and_max_idx(t_stack *stack, int *min_idx, int *max_idx)
{
	t_node	*node;
	int		idx;

	node = stack->head;
	idx = 0;
	while (node)
	{
		if (node->ranking == get_lowest_ranking_node(stack)->ranking)
			*min_idx = idx;
		if (node->ranking == get_highest_ranking_node(stack)->ranking)
			*max_idx = idx;
		node = node->next;
		idx ++;
	}
}
