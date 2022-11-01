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

