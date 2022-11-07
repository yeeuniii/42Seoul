/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:33 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 15:59:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*make_new_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->head = 0;
	stack->tail = 0;
	stack->size = 0;
	return (stack);
}

int	init_stack(t_stack **stack, t_numbers *numbers)
{
	int		idx;
	t_node	*new;

	idx = 0;
	while (idx < numbers->size)
	{
		new = make_new_node(ft_atoi(numbers->numbers[idx]));
		if (!new)
			return (0);
		add_node_back(stack, &new);
		idx ++;
	}
	free_numbers(numbers);
	return (1);
}
