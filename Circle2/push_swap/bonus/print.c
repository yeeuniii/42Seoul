/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:51:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/13 02:30:17 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_operation(char *operation_name, char stack_name)
{
	write(1, operation_name, ft_strlen(operation_name));
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	print_well_sorted(t_stack *a, t_stack *b)
{
	if (check_well_sorted(a) && !(b->size))
	{
		write(1, "OK\n", 3);
		return ;
	}
	write(1, "KO\n", 3);
}

void    print_all(t_stack *stack)
{
        t_node  *node;

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

void    print_stack(t_stack *a, t_stack *b)
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
