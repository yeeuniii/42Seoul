/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:16:05 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 03:27:47 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*head;
	t_node	*tmp;
	int		size;

	size = stack->size;
	if (size == 0 || size == 1)
		return ;
	head = stack->head;
	tmp = head->next;
	tmp->prev = 0;
	stack->head = tmp;
	if (!tmp->next)
		head->next = 0;
	if (tmp->next)
		connect(&head, &(tmp->next));
	connect(&tmp, &head);
}

void	swap_stack(t_stack *stack, char name)
{
	swap(stack);
	print_operation("s", name);
}
