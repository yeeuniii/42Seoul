#include "../includes/push_swap.h"

void	print_all(t_stack *stack)
{
	t_node	*node;
	
	node = stack->head;
	while (node)
	{
		printf("%d : ", node->number);
		if (node != stack->head)
			printf("head :%d, ", node->prev->number);
		if (node != stack->tail)
			printf("next :%d", node->next->number);
		node = node->next;
		printf("\n");
	}
}

void	test(t_stack *a, t_stack *b)
{
	printf("stack a : \n");
	print_all(a);
	printf("stack b : \n");
	print_all(b);
}
