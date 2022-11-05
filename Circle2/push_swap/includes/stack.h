/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:47:19 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 16:55:23 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "node.h"

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

t_stack	*make_new_stack(void);
int 	init_stack(t_stack **stack, t_numbers *numbers);

void	add_node_front(t_stack **stack, t_node **node);
void	add_node_back(t_stack **stack, t_node **node);
void	clear_stack(t_stack **stack);

void	swap(t_stack **stack);
void	push(t_stack **push_stack, t_stack **pop_stack);
void	rotate(t_stack **stack);
void	rotate_reverse(t_stack **stack);

#endif
