/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:33 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 03:23:47 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = 0;
	stack->tail = 0;
	stack->size = 0;
}

int	init_a_stack(t_stack *a, t_numbers *numbers)
{
	int		idx;
	t_node	*new;

	idx = 0;
	while (idx < numbers->size)
	{
		new = make_new_node(ft_atoi(numbers->numbers[idx]));
		if (!new)
			return (0);
		add_node_back(a, &new);
		idx ++;
	}
	free_numbers(numbers);
	return (1);
}
