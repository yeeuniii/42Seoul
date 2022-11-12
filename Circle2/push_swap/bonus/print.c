/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:51:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 02:47:53 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_operation(char *operation_name, char stack_name)
{
	write(1, operation_name, ft_strlen(operation_name));
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	print_well_sorted(t_stack *a, t_stack *b)
{
	if (check_well_sorted(a) && !(b->size))
	{
		write(1, "OK\n", 3);
		return ;
	}
	write(1, "KO\n", 3);
}
