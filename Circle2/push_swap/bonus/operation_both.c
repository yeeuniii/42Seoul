/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:15:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 14:20:36 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rotate_reverse_both(t_stack *a, t_stack *b)
{
	rotate_reverse(a);
	rotate_reverse(b);
}
