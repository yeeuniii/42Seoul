/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:21 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 19:09:56 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_sandglass(t_stack **a, t_stack **b, int chunk)
{
	int		idx;
	int		size;
	int		ranking;
	t_node	*head;

	idx = 0;
	size = (*a)->size;
	while (idx < size)
	{
		head = (*a)->head;
		ranking = head->ranking;
		if (ranking < idx)
		{
			push_stack(b, a, 'b');
			idx ++;
		}
		else if (idx <= ranking && ranking < idx + chunk)
		{
			push_stack(b, a, 'b');
			rotate_stack(b, 'b');
			idx ++;
		}
		else if (ranking >= idx + chunk)
			rotate_stack(a, 'a');
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	a_size;
	int	chunk;

	a_size = (*a)->size;
	chunk = 0.000000053 * a_size * a_size + 0.3 * a_size + 14.5;
	chunk = 2;
	make_sandglass(a, b, chunk);
}
