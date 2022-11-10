/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:14:45 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/10 22:12:22 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_node	*head;
	t_node	*tmp;
	int		size;

	size = (*stack)->size;
	if (size == 0 || size == 1)
		return ;
	head = (*stack)->head;
	tmp = head->next;
	tmp->prev = 0;
	(*stack)->head = tmp;
	connect(&head, &(tmp->next));
	connect(&tmp, &head);
}
