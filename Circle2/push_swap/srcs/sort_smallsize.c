/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 18:28:32 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_size3(t_stack **a, t_stack **b)
{
	t_node	*head;
	int		max_idx;
	int		min_idx;

	head = (*a)->head;
	if (!is_ascenging_ranking(*a))
		swap(a, 'a');
	if (check_well_sorted(*a))
		return ;
	find_min_and_max_idx(*a, &min_idx, &max_idx);
	(get_rotating_function(max_idx))(a, 'a');
	b = 0;
}

void	process_head_ranking(t_stack **a, t_stack **b, int *min_idx, int *max_idx)
{
	t_node	*head;

	head = (*a)->head;
	find_min_and_max_idx(*a, min_idx, max_idx);
	if (!*min_idx)
	{
		push(b, a, 'b');
		sort_size3(a, b);
		push(a, b, 'a');
		exit(0);
	}
	if (!*max_idx)
	{
		push(b, a, 'b');
		sort_size3(a, b);
		push(a, b, 'a');
		rotate(a, 'a');
		exit(0);
	}
}

void	sort_size4(t_stack **a, t_stack **b)
{
	t_node	*tail;
	int		max_ranking;
	int		min_idx;
	int		max_idx;

	tail = (*a)->tail;
	max_ranking = (*a)->size;
	min_idx = 0;
	max_idx = 0;
	process_head_ranking(a, b, &min_idx, &max_idx);
	if (min_idx == max_ranking || max_idx == max_ranking)
		rotate_reverse(a, 'a');
	else
		swap(a, 'a');
	if (check_well_sorted(*a))
		return ;
	process_head_ranking(a, b, &min_idx, &max_idx);
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
	sorting_func[1] = sort_size4;
//	sorting_func[2] = sort_size5;
	sorting_func[size - 3](a, b);
}
