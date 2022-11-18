/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 14:59:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	process_input(t_stack *a, t_stack *b, char *input)
{
	char	name;

	if (!input)
		return (-1);
	if (!is_correct_operation_name(input))
		return (0);
	name = input[ft_strlen(input) - 2];
	if (!ft_strcmp(input, "pa\n"))
		push(a, b);
	if (!ft_strcmp(input, "pb\n"))
		push(b, a);
	if (*input == 'p')
		return (1);
	if (*input != name && name == 'a')
		(get_single_operation_function(input))(a);
	if (*input != name && name == 'b')
		(get_single_operation_function(input))(b);
	if (*input == name)
		(get_both_operation_function(input))(a, b);
	return (1);
}

void	sort_by_standard_input(t_stack *a, t_stack *b)
{
	int		is_operation;
	char	*input;

	is_operation = 1;
	input = 0;
	while (is_operation > 0)
	{
		input = get_next_line(0);
		is_operation = process_input(a, b, input);
		free(input);
	}
	if (!is_operation)
	{
		clear_stack(a);
		clear_stack(b);
		print_error();
	}
}
