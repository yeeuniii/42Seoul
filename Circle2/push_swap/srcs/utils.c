/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:14:45 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 19:09:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_node	*head;
	int		size;
	int		tmp;

	size = (*stack)->size;
	if (size == 0 || size == 1)
		return ;
	head = (*stack)->head;
	tmp = head->next->number;
	head->next->number = head->number;
	head->number = tmp;
}

void	pop(t_stack **stack)
{
	t_node	*moving_node;
	int		size;

	moving_node = (*stack)->head;
	size = (*stack)->size;
	((*stack)->size)--;
	if (size == 1)
	{
		(*stack)->head = 0;
		(*stack)->tail = 0;
		return ;
	}
	(*stack)->head = moving_node->next;
	(*stack)->head->prev = 0;
	moving_node->next = 0;
}

void	push(t_stack **push_stack, t_stack **pop_stack)
{
	t_node	*moving_node;

	if ((*pop_stack)->size == 0)
		return ;
	moving_node = (*pop_stack)->head;
	pop(pop_stack);
	add_node_front(push_stack, &moving_node);
}

void	rotate(t_stack **stack)
{
	int		size;
	t_node	*head;

	size = (*stack)->size;
	if (size == 0 || size == 1)
		return ;
	head = (*stack)->head;
	(*stack)->head = head->next;
	(*stack)->head->prev = 0;
	head->next = 0;
	((*stack)->size)--;
	add_node_back(stack, &head);
}

void	rotate_reverse(t_stack **stack)
{
	int		size;
	t_node	*tail;

	size = (*stack)->size;
	if (size == 0 || size == 1)
		return ;
	tail = (*stack)->tail;
	(*stack)->tail = tail->prev;
	(*stack)->tail->next = 0;
	tail->prev = 0;
	((*stack)->size)--;
	add_node_front(stack, &tail);
}
