/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 00:12:19 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_size3(t_stack **a)
{
	int		max_idx;
	int		min_idx;

	if (!is_ascenging_ranking(*a))
		swap_stack(a, 'a');
	if (check_well_sorted(*a))
		return ;
	find_min_and_max_idx(*a, &min_idx, &max_idx);
	(get_rotating_function(max_idx))(a, 'a');
}

void	sort_size4(t_stack **a, t_stack **b)
{
	int	min_idx;
	int	max_idx;
	int	max_ranking;

	min_idx = 0;
	max_idx = 0;
	max_ranking = (*a)->size - 1;
	if (process_head_ranking(a, b, &min_idx, &max_idx))
		return ;
	if (min_idx == max_ranking || max_idx == max_ranking)
		rotate_reverse_stack(a, 'a');
	else
		swap_stack(a, 'a');
	if (check_well_sorted(*a))
		return ;
	process_head_ranking(a, b, &min_idx, &max_idx);
}

void	sort_size5(t_stack **a, t_stack **b)
{
	push_stack(b, a, 'b');
	sort_size4(a, b);
	push_stack(a, b, 'a');
	move_from_head(a);
}

void	sort_smallsize(int size, t_stack **a, t_stack **b)
{
	void	(*sorting_func[2])(t_stack **, t_stack **);

	if (size == 2)
	{
		swap_stack(a, 'a');
		return ;
	}
	if (size == 3)
	{
		sort_size3(a);
		return ;
	}
	sorting_func[0] = sort_size4;
	sorting_func[1] = sort_size5;
	sorting_func[size - 4](a, b);
}
