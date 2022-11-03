/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/03 16:27:27 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		is_error;

	a = make_new_stack();
	b = make_new_stack();
	is_error = !((a && b) && initialize(&a, argc, argv));
	handle_error(is_error, &a, &b);
	test(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
