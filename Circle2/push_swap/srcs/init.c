/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 22:00:26 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	initialize(t_stack **a, int argc, char *argv[])
{
	int		idx;
	int		limit;
	char	**numbers;
	t_node	*new;

	if (argc == 1)
		return (0);
	idx = 0;
	numbers = get_numbers(argc, argv, &limit);
	while (idx < limit && check_argument(*a, numbers[idx]))
	{
		new = make_new_node(ft_atoi(numbers[idx]));
		if (!new)
		{
			free_numbers(argc, numbers);
			return (0);
		}
		add_node_back(a, &new);
		idx++;
	}
	free_numbers(argc, numbers);
	return (idx == limit);
}
