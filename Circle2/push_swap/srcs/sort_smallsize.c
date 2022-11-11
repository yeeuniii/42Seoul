/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 14:48:39 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_ascenging_ranking(t_stack *a, int *max_idx)
{
	int		idx;
	int		min_idx;
	int		size;
	t_node	*node;

	idx = 0;
	min_idx = 0;
	size = a->size;
	node = a->head;
	while (node->ranking)
	{
		node = node->next;
		min_idx ++;
	}
	while (idx < size)
	{
		if (idx != node->ranking)
			return (0);
		node = node->next;
		if (!node)
			node = a->head;
		idx ++;
	}
	*max_idx = min_idx - 1;
	return (1);
}

void	sort_size3(t_stack **a, t_stack **b)
{
	t_node	*head;
	int		max_idx;

	head = (*a)->head;
	if (!is_ascenging_ranking(*a, &max_idx))
		swap(a, 'a');
	if (check_well_sorted(*a))
		return ;
	is_ascenging_ranking(*a, &max_idx);
	(get_rotating_function(max_idx))(a, 'a');
	b = 0;
}

void	sort_smallsize(int size, t_stack **a, t_stack **b)
{
	void	(*sorting_func[3])(t_stack **, t_stack **);

	if (size == 2)
	{
		swap(a, 'a');
		return ;
	}
	sorting_func[0] = sort_size3;
//	sorting_func[1] = sort_size4;
//	sorting_func[2] = sort_size5;
	sorting_func[size - 3](a, b);
}
