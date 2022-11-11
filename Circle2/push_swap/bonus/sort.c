/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:43:49 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 22:59:48 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_correct_operation_name(char *name)
{	
	return (!(ft_strcmp(name, "sa") && ft_strcmp(name, "sb") && ft_strcmp(name, "ss")
			&& ft_strcmp(name, "pa") && ft_strcmp(name, "pb") 
			&& ft_strcmp(name, "ra") && ft_strcmp(name, "rb") && ft_strcmp(name, "rr")
			&& ft_strcmp(name, "rra") && ft_strcmp(name, "rrb") && ft_strcmp(name, "rrr")));
}

void	sort_by_standard_inpust(t_stack **a, t_stack **b)
{
	char	*input;

	while (*input != '\n')
	{
		input = get_next_line(0);

	}

}
