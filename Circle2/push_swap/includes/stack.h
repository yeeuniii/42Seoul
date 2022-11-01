#ifndef STACK_H
# define STACK_H

# include "node.h"

typedef struct s_stack
{
	unsigned int	size;
	t_node			*head;
	t_node			*tail;
}	t_stack;

t_stack	*make_new_stack(void);
int		initialize(t_stack **a, int argc, char *argv[]);
void	add_node_front(t_stack **stack, t_node **node);
void	add_node_back(t_stack **stack, t_node **node);
void	clear_stack(t_stack **stack);

void	swap(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	rotate_reverse(t_stack **stack);

#endif
