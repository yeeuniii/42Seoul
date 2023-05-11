/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:32:44 by yeepark           #+#    #+#             */
/*   Updated: 2023/02/25 11:45:46 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <string.h>

t_global	g_global;

int	main(int argc, char *argv[], char **envp)
{
	t_node	*node;
	int		idx;

	init_envp(envp);
	node = malloc(sizeof(t_node));
	node->arg_cnt = argc;
	node->command_arg = malloc(sizeof(char *) * (argc + 1));
	node->command_arg[0] = strdup("echo");
	idx = 1;
	while (idx < argc)
	{
		node->command_arg[idx] = strdup(argv[idx]);
		idx++;
	}
	node->command_arg[argc] = 0;

	ft_echo(node);
	exit(0);
}
