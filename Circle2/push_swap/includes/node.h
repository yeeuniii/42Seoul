/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:13:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/04 16:55:08 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

typedef struct s_node
{
	int				number;
	int				ranking;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

t_node	*make_new_node(int number);
void	connect(t_node **front, t_node **back);

#endif
