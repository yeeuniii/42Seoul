/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:16:05 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 14:57:42 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*head;
	t_node	*new_head;
	int		size;

	size = stack->size;
	if (size == 0 || size == 1)
		return ;
	head = stack->head;
	new_head = head->next;
	new_head->prev = 0;
	stack->head = new_head;
	head->next = 0;
	if (!new_head->next)
		stack->tail = head;
	if (new_head->next)
		connect(&head, &(new_head->next));
	connect(&new_head, &head);
}
