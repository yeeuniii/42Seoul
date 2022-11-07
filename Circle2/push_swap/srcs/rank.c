/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 15:59:58 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_ranking(t_stack *stack, t_node *node)
{
	t_node	*cmp_node;
	int		ranking;

	cmp_node = stack->head;
	ranking = 0;
	while (cmp_node)
	{
		if (cmp_node->number < node->number)
			ranking ++;
		cmp_node = cmp_node->next;
	}
	return (ranking);
}

void	rank(t_stack **stack)
{
	t_node	*node;

	node = (*stack)->head;
	while (node)
	{
		node->ranking = get_ranking(*stack, node);
		node = node->next;
	}
}
