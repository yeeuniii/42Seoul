/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 15:37:54 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_numbers(int argc, char *argv[], int *idx, int *limit)
{
	char	**numbers;

	if (argc > 2)
		numbers = argv;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ', limit);
		*idx = 0;
	}
	if (!numbers)
		*idx = *limit + 1;
	return (numbers);
}

void	free_numbers(int condition, char **numbers)
{
	int	idx;

	if (!condition)
		return ;
	idx = 0;
	while (numbers[idx])
	{
		free(numbers[idx]);
		idx ++;
	}
	free(numbers);
}

int	initialize(t_stack **a, int argc, char *argv[])
{
	int		idx;
	int		limit;
	char	**numbers;
	t_node	*new;

	if (argc == 1)
		return (0);
	idx = 1;
	limit = argc;
	numbers = get_numbers(argc, argv, &idx, &limit);
	while (idx < limit && check_argument(*a, numbers[idx]))
	{
		new = make_new_node(ft_atoi(numbers[idx]));
		if (!new)
		{
			free_numbers(limit != argc, numbers);
			return (0);
		}
		add_node_back(a, &new);
		idx++;
	}
	free_numbers(limit != argc, numbers);
	return (idx == limit);
}
