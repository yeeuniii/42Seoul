/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:08:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/28 22:36:08 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_error(void)
{
	ft_printf("%s\n", "Error\n");
	exit(1);
}

void	check_arg(int argc, char *argv[])
{
	int	idx;

	if (argc == 1)
		exit(0);
	idx = 1;
	while (--argc)
	{
		if (!ft_isdigit(argv[idx]))
			ft_error();
		idx ++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	check_arg(argc, argv);
	initialize_stack;
	return (0);
}
