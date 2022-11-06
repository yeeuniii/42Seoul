#include "../includes/push_swap.h"

int	get_ranking(t_stack *stack, t_node *node)
{
	t_node	*cmp_node;
	int		ranking;

	cmp_node = stack->head;
	ranking = 0;
	while (cmp_node)
	{
		if (cmp_node->number < node->number)
			ranking ++;
		cmp_node = cmp_node->next;
	}
	return (ranking);
}


void	rank(t_stack **stack)
{
	t_node	*node;

	node = (*stack)->head;
	while (node)
	{
		node->ranking = get_ranking(*stack, node);
		node = node->next;
	}
}
