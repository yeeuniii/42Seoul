/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:05:21 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/31 20:48:43 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stack(t_stack **a, int argc, char *argv[])
{
	int	idx;

	idx = 1;
	while (idx < argc && ft_isinteger(argv[idx]))
	{
		ft_stackadd_back(a, ft_stacknew(ft_atoi(argv[idx]), *a));
		idx ++;
	}
	if (idx != argc)
	{
		ft_stackclear(a);
		ft_error();
	}
}
