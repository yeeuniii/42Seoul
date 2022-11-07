/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:19:42 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 16:36:17 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_output_str(char *operation_name, char stack_name)
{
	write(1, operation_name, ft_strlen(operation_name));
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	swap_stack(t_stack **stack, char name)
{
	swap(stack);
	print_output_str("s", name);
}

void	push_stack(t_stack **push_stack, t_stack **pop_stack, char name)
{
	push(push_stack, pop_stack);
	print_output_str("p", name);
}

void	rotate_stack(t_stack **stack, char name)
{
	rotate(stack);
	print_output_str("r", name);
}

void	rotate_reverse_stack(t_stack **stack, char name)
{
	rotate_reverse(stack);
	print_output_str("rr", name);
}
