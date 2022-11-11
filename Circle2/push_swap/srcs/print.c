/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:51:36 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/11 14:51:39 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_operation(char *operation_name, char stack_name)
{
	write(1, operation_name, ft_strlen(operation_name));
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

