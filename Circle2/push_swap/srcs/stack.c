/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:18:28 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/31 20:37:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int number, t_stack *stack)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new) //lstclear하고
		ft_error();
	new->number = number;
	new->front = ft_stacklast(stack);
	new->next = 0;
	return (new);
}

int	ft_stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size ++;
		stack = stack->next;
	}
	return (size);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
