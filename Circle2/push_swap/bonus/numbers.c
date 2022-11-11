/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:38 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 15:59:39 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_numbers(int argc, char *argv[], t_numbers *numbers)
{
	numbers->can_free = 0;
	if (argc == 1)
		return (0);
	if (argc > 2)
	{
		numbers->numbers = argv + 1;
		numbers->size = argc - 1;
		return (1);
	}
	numbers->numbers = ft_split(argv[1], ' ', &(numbers->size));
	numbers->can_free = 1;
	if (!numbers->numbers)
		return (0);
	return (1);
}

int	check_numbers(t_numbers *numbers)
{
	int	idx;

	idx = 0;
	while (idx < numbers->size && check(numbers->numbers, idx))
		idx ++;
	return (idx == numbers->size);
}

void	free_numbers(t_numbers *numbers)
{
	int	idx;

	idx = 0;
	if (!numbers->can_free)
		return ;
	while (idx < numbers->size)
	{
		free((numbers->numbers)[idx]);
		idx ++;
	}
	free(numbers->numbers);
}
