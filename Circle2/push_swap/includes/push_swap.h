/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:13:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/16 02:19:26 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "numbers.h"
# include "stack.h"
# include "../libft/includes/libft.h"
# include "get_next_line.h"

int		check_numbers_all(char **numbers, int idx);
void	print_error(void);
void	handle_error(int is_error, t_stack *a, t_stack *b, t_numbers *nbrs);
void	print_operation(char *operation_name, char stack_name);

int		is_correct_operation_name(char *name);

#endif
