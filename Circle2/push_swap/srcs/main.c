/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/31 21:07:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_all(t_stack *stack)
{
	t_stack	*tmp;

	tmp = ft_stacklast(stack);
	while (tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->front;
	}
	printf("\n");
}

void	test(t_stack *a, t_stack *b)
{
	printf("---initialize---\n");
	printf("a\n");
	print_all(a);
	printf("b\n");
	print_all(b);

	printf("---swap_a---\n");
	swap(&a);
	printf("a\n");
	print_all(a);
	printf("b\n");
	print_all(b);

	printf("---push_a---\n");
	push(&a, &b);
	printf("a\n");
	print_all(a);
	printf("b\n");
	print_all(b);
	
	printf("---push_b---\n");
	push(&b, &a);
	printf("a\n");
	print_all(a);
	printf("b\n");
	print_all(b);

	printf("---rotate_a---\n");
	rotate(&a);
	printf("a\n");
	print_all(a);
	printf("b\n");
	print_all(b);

	printf("---rotate_reverse__a---\n");
	rotate_reverse(&a);
	printf("a\n");
	print_all(a);
	printf("b\n");
	print_all(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_arg(argc, argv);
	initialize_stack(&a, argc, argv);
	test(a, b);
	return (0);
}
