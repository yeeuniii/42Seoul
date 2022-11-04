/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 16:55:48 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_all(t_stack *stack)
{
	t_node	*node;
	
	node = stack->head;
	if (stack->size)
	{
		printf("head : %d, ", stack->head->number);
		printf("tail : %d\n", stack->tail->number);
	}
	while (node)
	{
		printf("number : %d\t", node->number);
//		printf("ranking : %d\t", node->ranking);
		if (node != stack->head)
			printf("prev : %d, ", node->prev->number);
		if (node != stack->tail)
			printf("next : %d", node->next->number);
		node = node->next;
		printf("\n");
	}
}

void	print_stack(t_stack *a, t_stack *b)
{
	printf("stack a\n");
	print_all(a);
	if (!a->size)
		printf("empty\n");
	printf("stack b\n");
	print_all(b);
	if (!b->size)
		printf("empty\n");
	printf("\n\n");
}

void	test(t_stack **a, t_stack **b)
{
	printf("origin\n");
	print_stack(*a, *b);

//	printf("swap a\n");
//	swap(a);
//	print_stack(*a, *b);
//
//	printf("push b pop a\n");
//	push(b, a);
//	print_stack(*a, *b);
//	printf("a size : %d, b size : %d\n", (*a)->size, (*b)->size);
//
//	printf("push a pop b\n");
//	push(a, b);
//	print_stack(*a, *b);
//	printf("a size : %d, b size : %d\n", (*a)->size, (*b)->size);
//	
//	printf("rotate a\n");
//	rotate(a);
//	print_stack(*a, *b);
//	
//	printf("rotate reverse a\n");
//	rotate_reverse(a);
//	print_stack(*a, *b);
}
