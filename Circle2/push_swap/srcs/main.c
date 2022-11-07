/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 17:18:39 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_numbers	numbers;
	t_stack		*a;
	t_stack		*b;
	int			is_error;

	is_error = !(init_numbers(argc, argv, &numbers) && check_numbers(&numbers));
	a = make_new_stack();
	b = make_new_stack();
	is_error = (is_error || !((a && b) && init_stack(&a, &numbers)));
	handle_error(is_error, &a, &b, &numbers);
	rank(&a);
	test(&a, &b);
//	sort(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
