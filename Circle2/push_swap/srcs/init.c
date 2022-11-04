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

char	**get_numbers(int argc, char *argv[], int *limit, int *idx)
{
	char	**numbers;

	if (argc > 2)
	{
		numbers = argv;
		*limit = argc;
		*idx = 1;
	}
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ', limit);
		*idx = 0;
	}
	if (!numbers)
		*idx = argc + 1;
	return (numbers);
}

void	free_numbers(int argc, char **numbers)
{
	int	idx;

	if (argc != 2)
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
	int		freed;
	char	**numbers;
	t_node	*new;

	if (argc == 1)
		return (0);
	numbers = get_numbers(argc, argv, &limit, &idx);
	freed = (limit != argc);
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
