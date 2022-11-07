/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:18 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/07 15:59:19 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_H
# define NUMBERS_H

typedef struct s_numbers
{
	char	**numbers;
	int		size;
	int		can_free;
}	t_numbers;

# define INT_MAX 2147483647
# define INT_MIN -2147483648

int		init_numbers(int argc, char *argv[], t_numbers *numbers);
int		check_numbers(t_numbers *numbers);
void	free_numbers(t_numbers *numbers);

#endif
