/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:58:37 by yeepark           #+#    #+#             */
/*   Updated: 2023/03/19 16:57:54 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern t_global	g_global;

void	handle_node(t_node *node)
{
	if (node->type == REDIRECT)
		handle_redirect(node);
	if (node->type == COMMAND)
		handle_command(node);
}

void	search_node(t_node *node)
{
	if (node->left)
		search_node(node->left);
	if (node->right)
		search_node(node->right);
	printf("search_node : %d\n", node->type);
	handle_node(node);
}

void	search_tree(t_node *node)
{
	int		pipe[2][2];
	int		cnt;
	pid_t	pid;

	if (handle_singlebuiltin(node))
		return ;
	cnt = 0;
	open_pipe(pipe[OLD]);
	while (node)
	{
		g_global.err_num = NaE;
		pid = handle_process(node, pipe, &cnt);
		printf("in while : %d\n", node->type);
		printf("redirect_type : %d\n", node->redirect_type);
		node = node->right;
	}
	close_pipe(pipe[OLD]);
	wait_process(pid, cnt);
}
