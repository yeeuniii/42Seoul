/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:13:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/10/31 20:49:58 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "type.h"
# include "../printf/includes/ft_printf.h"
# include "../printf/libft/includes/libft.h"

void	ft_error(void);
void	check_arg(int argc, char *argv[]);	
int		ft_isinteger(char *str);

void	initialize_stack(t_stack **stack, int argc, char *argv[]);

void	swap(t_stack **stack);
void	push(t_stack **stack1, t_stack **stack2);
void	rotate(t_stack **stack);
void	rotate_reverse(t_stack **stack);

t_stack	*ft_stacknew(int number, t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);

#endif
