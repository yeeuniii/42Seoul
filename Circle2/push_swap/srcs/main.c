/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 03:33:15 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_numbers	numbers;
	t_stack		a;
	t_stack		b;
	int			is_error;

	is_error = !(init_numbers(argc, argv, &numbers) && check_numbers(&numbers));
	init_stack(&a);
	init_stack(&b);
	is_error = (is_error || !init_a_stack(&a, &numbers));
	handle_error(is_error, &a, &b, &numbers);
	rank(&a);
	sort(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
