/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:56:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 18:27:44 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isinteger(char *str)
{
	long	res;
	int		idx;
	int		sign;
	int		digit;

	res = 0;
	idx = 0;
	sign = 1;
	digit = 0;
	if (str[idx] == '+' || str[idx] == '-')
	{
		sign = (str[idx] == '+') - (str[idx] == '-');
		idx ++;
	}
	while (ft_isdigit(str[idx]) && digit < 11)
	{
		res = res * 10 + str[idx] - '0';
		idx ++;
		digit ++;
	}
	if ((!ft_isdigit(str[idx]) && str[idx]) || digit == 11)
		return (0);
	if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
		return (0);
	return (1);
}

int	check_duplicated(char **numbers, int end_idx)
{
	int	start_idx;

	start_idx = 0;
	while (start_idx < end_idx)
	{
		if (!ft_strcmp(numbers[start_idx], numbers[end_idx]))
			return (0);
		start_idx ++;
	}
	return (1);
}

int	check(char **numbers, int idx)
{
	return (ft_isinteger(numbers[idx]) && check_duplicated(numbers, idx));
}

int	check_well_sorted(t_stack *stack)
{
	t_node	*node;
	int		prev_number;

	node = stack->head;
	while (node->next)
	{
		prev_number = node->number;
		node = node->next;
		if (prev_number > node->number)
			return (0);
	}
	return (1);
}

int	is_ascenging_ranking(t_stack *stack)
{
	int		idx;
	int		size;
	int		prev_ranking;
	t_node	*node;

	idx = 0;
	size = stack->size;
	node = get_lowest_ranking_node(stack);
	prev_ranking = node->ranking;
	while (idx < size)
	{
		if (prev_ranking > node->ranking)
			return (0);
		prev_ranking = node->ranking;
		node = node->next;
		if (!node)
			node = stack->head;
		idx ++;
	}
	return (1);
}

