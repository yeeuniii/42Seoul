/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:56:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/03 21:48:07 by yeepark          ###   ########.fr       */
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

int	check_duplicated(t_stack *stack, int num)
{
	t_node	*node;

	node = stack->head;
	while (node && num != node->number)
		node = node->next;
	return (!node);
}

int	check_argument(t_stack *stack, char *str)
{
	return (ft_isinteger(str) && check_duplicated(stack, ft_atoi(str)));
}
