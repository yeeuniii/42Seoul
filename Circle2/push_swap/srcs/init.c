/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/03 21:49:26 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_numbers(int argc, char *argv[])
{
	char	**numbers;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	if (argc > 2)
		numbers = argv;
	return (numbers);
}

int	initialize(t_stack **a, int argc, char *argv[])
{
	int		idx;
	t_node	*new;
	char	**numbers;

	idx = 1;
	if (argc == 1)
		return (0);
	numbers = get_numbers(argc, argv);
	while (idx < argc && check_argument(*a, numbers[idx]))
	{
		new = make_new_node(ft_atoi(numbers[idx]));
		if (!new)
			return (0);
		add_node_back(a, &new);
		idx++;
	}
	return (idx == argc);
}
