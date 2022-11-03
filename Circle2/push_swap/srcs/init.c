/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/03 19:17:15 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	initialize(t_stack **a, int argc, char *argv[])
{
	int		idx;
	t_node	*new;

	idx = 1;
	if (argc == 1)
		return (0);
	while (idx < argc && ft_isinteger(argv[idx]))
	{
		new = make_new_node(ft_atoi(argv[idx]));
		if (!new)
			return (0);
		add_node_back(a, &new);
		idx++;
	}
	return (idx == argc);
}
