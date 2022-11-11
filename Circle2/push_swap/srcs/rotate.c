/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:06:39 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 22:08:30 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rotate_stack(t_stack **stack, char name)
{
	rotate(stack);
	print_operation("r", name);
}

void	rotate_reverse_stack(t_stack **stack, char name)
{
	rotate_reverse(stack);
	print_operation("rr", name);
}

void	(*get_rotating_function(int reverse))(t_stack **stack, char c)
{
	if (reverse)
		return (rotate_reverse_stack);
	return (rotate_stack);
}
