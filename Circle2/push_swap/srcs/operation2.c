/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:31:30 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 16:34:24 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss", 2);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr", 2);
}

void	rotate_reverse_both(t_stack **a, t_stack **b)
{
	rotate_reverse(a);
	rotate_reverse(b);
	write(1, "rrr", 2);
}
