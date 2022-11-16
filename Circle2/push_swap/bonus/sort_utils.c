/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 14:25:18 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_correct_operation_name(char *name)
{	
	return (!(ft_strcmp(name, "sa\n") && ft_strcmp(name, "sb\n")
			&& ft_strcmp(name, "ss\n") && ft_strcmp(name, "pa\n")
			&& ft_strcmp(name, "pb\n") && ft_strcmp(name, "ra\n")
			&& ft_strcmp(name, "rb\n") && ft_strcmp(name, "rr\n")
			&& ft_strcmp(name, "rra\n") && ft_strcmp(name, "rrb\n")
			&& ft_strcmp(name, "rrr\n")));
}

void	(*get_single_operation_function(char *input))(t_stack *stack)
{
	if (*input == 's')
		return (swap);
	if (ft_strlen(input) == 3)
		return (rotate);
	return (rotate_reverse);
}

void	(*get_both_operation_function(char *input))(t_stack *a, t_stack *b)
{
	if (*input == 's')
		return (swap_both);
	if (ft_strlen(input) == 3)
		return (rotate_both);
	return (rotate_reverse_both);
}

int	check_well_sorted(t_stack stack)
{
	t_node	*node;
	int		prev_number;

	node = stack.head;
	while (node->next)
	{
		prev_number = node->number;
		node = node->next;
		if (prev_number > node->number)
			return (0);
	}
	return (1);
}
