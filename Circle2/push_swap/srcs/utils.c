/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:18:31 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/31 21:08:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*top;
	int		size;
	int		tmp;

	top = *stack;
	size = ft_stacksize(top);
	if (size == 0 || size == 1)
		return ;
	tmp = top->next->number;
	top->next->number = top->number;
	top->number = tmp;	
}

void	push(t_stack **stack1, t_stack **stack2) // 2->1
{
	t_stack	*tmp;

	if (ft_stacksize(*stack2) == 0)
		return ;
	tmp = (*stack2)->next;
	(*stack2)->next = 0;
	ft_stackadd_front(stack1, *stack2);
	(*stack2) = tmp;
}

void	rotate(t_stack **stack)
{
	t_stack *tmp;
	int		size;

	size = ft_stacksize(*stack);
	if (size == 0 || size == 1)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = 0;
	ft_stackadd_back(&tmp, *stack);
	(*stack) = tmp;
}

void	rotate_reverse(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	size = ft_stacksize(*stack);
	if (size == 0 || size == 1)
		return ;
	tmp = ft_stacklast(*stack);
	printf("front : %d\n", tmp->front->number);
	ft_stackadd_front(stack, tmp);
}
