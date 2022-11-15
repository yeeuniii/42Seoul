/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 01:22:34 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_ranking(t_stack stack, t_node *node)
{
	t_node	*cmp_node;
	int		ranking;

	cmp_node = stack.head;
	ranking = 0;
	while (cmp_node)
	{
		if (cmp_node->number < node->number)
			ranking ++;
		cmp_node = cmp_node->next;
	}
	return (ranking);
}

void	rank(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		node->ranking = get_ranking(*stack, node);
		node = node->next;
	}
}

t_node	*get_lowest_ranking_node(t_stack stack)
{
	t_node	*node;
	t_node	*min_node;

	node = stack.head;
	min_node = node;
	while (node)
	{
		if (min_node->ranking > node->ranking)
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

t_node	*get_highest_ranking_node(t_stack stack)
{
	t_node	*node;
	t_node	*max_node;

	node = stack.head;
	max_node = node;
	while (node)
	{
		if (max_node->ranking < node->ranking)
			max_node = node;
		node = node->next;
	}
	return (max_node);
}

void	find_min_and_max_idx(t_stack stack, int *min_idx, int *max_idx)
{
	t_node	*node;
	t_node	*max_node;
	t_node	*min_node;
	int		idx;

	node = stack.head;
	max_node = get_highest_ranking_node(stack);
	min_node = get_lowest_ranking_node(stack);
	idx = 0;
	while (node)
	{
		if (node->ranking == max_node->ranking)
			*min_idx = idx;
		if (node->ranking == min_node->ranking)
			*max_idx = idx;
		node = node->next;
		idx ++;
	}
}
