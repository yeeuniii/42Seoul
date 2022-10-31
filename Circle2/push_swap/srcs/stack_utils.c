/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:49:26 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/31 21:03:11 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (*stack)
	{
		new->next = *stack;
		(*stack)->front = new;
		*stack = new;	
	}
	if (!*stack)
		*stack = new;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (*stack)
	{
		ft_stacklast(*stack)->next = new;
		new->front = ft_stacklast(*stack)->next;
	}
	if (!*stack)
		*stack = new;
}
