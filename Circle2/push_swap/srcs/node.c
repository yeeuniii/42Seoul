/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:52 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 15:59:02 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*make_new_node(int number)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (new);
	new->number = number;
	new->prev = 0;
	new->next = 0;
	return (new);
}

void	connect(t_node **front, t_node **back)
{
	(*back)->prev = *front;
	(*front)->next = *back;
}
