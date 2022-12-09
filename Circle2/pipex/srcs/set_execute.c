/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:33:21 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 14:51:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*join_path_and_cmd(char *envp, char *cmd)
{
	size_t	idx;
	size_t	envp_size;
	size_t	cmd_size;
	char	*cmd_path;

	idx = 0;
	envp_size = ft_strlen(envp);
	cmd_size = ft_strlen(cmd);
	cmd_path = malloc(sizeof(char) * (envp_size + cmd_size + 2));
	if (!cmd_path)
		return (0);
	while (*envp && idx < envp_size)
	{
		cmd_path[idx] = envp[idx];
		idx++;
	}
	cmd_path[idx++] = '/';
	while (*cmd && idx < envp_size + cmd_size + 1)
	{
		cmd_path[idx] = cmd[idx - envp_size - 1];
		idx++;
	}
	cmd_path[idx] = 0;
	return (cmd_path);
}

char	*find_command_path(t_execute execute)
{
	int		idx;
	char	*cmd;
	char	*cmd_path;

	idx = 0;
	cmd = execute.cmd_vector[0];
	cmd_path = 0;
	while (execute.env_path[idx])
	{
		cmd_path = join_path_and_cmd(execute.env_path[idx], cmd);
		if (!cmd_path)
			print_error_by_errno();
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		idx++;
	}
	execute.is_command = 0;
	print_error(cmd, NOT_COMMAND);
	return (0);
}

t_execute	set_execute(char **envp, char *cmd)
{
	t_execute	execute;

	execute.is_command = 1;
	execute.cmd_path = 0;
	execute.env_path = envp;
	execute.cmd_vector = ft_split(cmd, ' ');
	if (!execute.cmd_vector)
		free_execute(execute, 1);
	execute.cmd_path = find_command_path(execute);
	return (execute);
}
