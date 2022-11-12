/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 00:13:07 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	process_head_ranking(t_stack **a, t_stack **b, int *min_idx, int *max_idx)
{
	find_min_and_max_idx(*a, min_idx, max_idx);
	if (!*min_idx)
	{
		push_stack(b, a, 'b');
		sort_size3(a);
		push_stack(a, b, 'a');
		return (1);
	}
	if (!*max_idx)
	{
		push_stack(b, a, 'b');
		sort_size3(a);
		push_stack(a, b, 'a');
		rotate_stack(a, 'a');
		return (1);
	}
	return (0);
}

void	move_from_head(t_stack **a)
{
	t_node	*head;

	head = (*a)->head;
	if (head->ranking == 1)
		swap_stack(a, 'a');
	else if (head->ranking == 2)
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
		swap_stack(a, 'a');
		rotate_reverse_stack(a, 'a');
	}
	else if (head->ranking == 3)
	{
		rotate_reverse_stack(a, 'a');
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else if (head->ranking == 4)
		rotate_stack(a, 'a');
}
