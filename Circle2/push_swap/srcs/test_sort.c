/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 21:23:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_size3(t_stack **a, t_stack **b)
{
	int		max_idx;
	int		min_idx;

	if (!is_ascenging_ranking(*a))
		swap(a, 'a');
	if (check_well_sorted(*a))
		return ;
	find_min_and_max_idx(*a, &min_idx, &max_idx);
	(get_rotating_function(max_idx))(a, 'a');
	b = 0;
}

void	move_to_correct_pos(t_stack **a)
{
	t_node	*head;
	
	head = (*a)->head;
	if (head->ranking == 1)
	{
		swap(a, 'a');
		return ;
	}
	if (head->ranking == 2)
	{
		rotate_reverse(a, 'a');
		swap(a, 'a');
		rotate(a, 'a');
		rotate(a, 'a');
		return ;
	}
	if (head->ranking == 3)
	{
		rotate(a, 'a');
		return ;
	}
}

void	sort_size4(t_stack **a, t_stack **b)
{
	push(b, a, 'b');
	rank(a);
	sort_size3(a, b);
	push(a, b, 'a');
	move_to_correct_pos(a);
	
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
//	print_stack(*a, *b);
}
