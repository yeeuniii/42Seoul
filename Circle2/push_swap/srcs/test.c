/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:44:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 14:54:08 by yeepark          ###   ########.fr       */
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
		printf("ranking : %d\t", node->ranking);
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

void	test_push(t_stack **a, t_stack **b)
{
	int		idx = 0;
	int		size = (*a)->size;

	while (idx < size)
	{
		push(b, a, 'b');
		print_stack(*a, *b);
		idx ++;
	}
}

void	test(t_stack **a, t_stack **b)
{
	printf("origin\n");
	printf("a size : %d\n", (*a)->size);
	printf("b size : %d\n", (*b)->size);
	print_stack(*a, *b);

//	printf("push b from a\n");
//	test_push(a, b);

	printf("sort\n");
	sort(a, b);
	print_stack(*a, *b);

//	printf("swap a\n");
//	swap_stack(a, 'a');
//	print_stack(*a, *b);
//
//	printf("push b pop a\n");
//	push_stack(b, a, 'b');
//	print_stack(*a, *b);
//	printf("a size : %d, b size : %d\n", (*a)->size, (*b)->size);
//
//	printf("push a pop b\n");
//	push_stack(a, b, 'a');
//	print_stack(*a, *b);
//	printf("a size : %d, b size : %d\n", (*a)->size, (*b)->size);
//	
//	printf("rotate a\n");
//	rotate_stack(a, 'a');
//	print_stack(*a, *b);
//	
//	printf("rotate reverse a\n");
//	rotate_reverse_stack(a, 'a');
//	print_stack(*a, *b);
}
