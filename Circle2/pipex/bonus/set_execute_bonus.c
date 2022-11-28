/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_execute_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:39:11 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/28 21:39:17 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_execute(t_execute execute, int is_error)
{
	free(execute.cmd_path);
	free_two_dim(execute.cmd_vector);
	if (is_error)
	{
		free_two_dim(execute.env_path);
		exit(1);
	}
}

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
	while (idx >= 0 && execute.env_path[idx])
	{
		free(cmd_path);
		cmd_path = join_path_and_cmd(execute.env_path[idx], cmd);
		if (!cmd_path)
			idx = -2;
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		idx++;
	}
	print_error(cmd);
	free_execute(execute, 1);
	return (0);
}

t_execute	set_execute(char **envp, char *cmd)
{
	t_execute	execute;

	execute.env_path = envp;
	execute.cmd_vector = ft_split(cmd, ' ');
	if (!execute.cmd_vector)
	{
		execute.cmd_path = 0;
		free_execute(execute, 1);
		exit(1);
	}
	execute.cmd_path = find_command_path(execute);
	return (execute);
}
