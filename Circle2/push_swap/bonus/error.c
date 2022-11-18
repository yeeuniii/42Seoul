/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:57:16 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 03:15:29 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	handle_error(int is_error, t_stack *a, t_stack *b, t_numbers *numbers)
{
	if (is_error)
	{
		clear_stack(a);
		clear_stack(b);
		free_numbers(numbers);
		print_error();
	}
}
