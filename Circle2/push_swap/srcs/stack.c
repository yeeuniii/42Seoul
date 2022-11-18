/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:54 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 03:24:31 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_empty_stack(t_stack *stack, t_node *node)
{
	if (!(stack->size))
	{
		stack->head = node;
		stack->tail = node;
	}
}

void	add_node_front(t_stack *stack, t_node **node)
{
	set_empty_stack(stack, *node);
	if (stack->size)
	{
		connect(node, &(stack->head));
		stack->head = *node;
	}
	(stack->size)++;
}

void	add_node_back(t_stack *stack, t_node **node)
{
	set_empty_stack(stack, *node);
	if (stack->size)
	{
		connect(&(stack->tail), node);
		stack->tail = *node;
	}
	(stack->size)++;
}

void	clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if (!stack->head)
		return ;
	node = stack->head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
