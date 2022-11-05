/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 22:00:36 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_numbers(int argc, char *argv[], int *size)
{
	char	**numbers;

	if (argc > 2)
	{
		numbers = argv + 1;
		*size = argc - 1;
	}
	if (argc == 2)
    	numbers = ft_split(argv[1], ' ', size);
	if (!(numbers && check_numbers(numbers, *size)))
		return (0);
	return (numbers);
}

int	main(int argc, char *argv[])
{
	t_numbers	*numbers;
	t_stack		*a;
	t_stack		*b;
	int			is_error;
	int			size;

	numbers = make_numbers(get_numbers(argc, argv, &size), size);
	a = make_new_stack();
	b = make_new_stack();
	is_error = !((a && b) && initialize(&a, argc, argv));
	handle_error(is_error, &a, &b);
	test(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
