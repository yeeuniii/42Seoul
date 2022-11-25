/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:22:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 21:09:08 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*join_path_and_cmd(char *path, char *cmd)
{
	size_t	idx;
	size_t	path_size;
	size_t	cmd_size;
	char	*cmd_path;

	idx = 0;
	path_size = ft_strlen(path);
	cmd_size = ft_strlen(cmd);
	cmd_path = malloc(sizeof(char) * (path_size + cmd_size + 2));
	if (!cmd_path)
		return (0);
	while (*path && idx < path_size)
	{
		cmd_path[idx] = path[idx];
		idx++;
	}
	cmd_path[idx++] = '/';
	while (*cmd && idx < path_size + cmd_size + 1)
	{
		cmd_path[idx] = cmd[idx - path_size - 1];
		idx++;
	}
	cmd_path[idx] = 0;
	return (cmd_path);
}

char	*find_command_path(char *cmd, char **path)
{
	int		idx;
	int		failed;
	char	*cmd_path;

	idx = 0;
	failed = 0;
	cmd_path = 0;
	while (!failed && path[idx] && access(cmd_path, F_OK))
	{
		free(cmd_path);
		cmd_path = join_path_and_cmd(path[idx], cmd);
		if (!cmd_path)
			failed = 1;
		idx++;
	}
	if (failed || access(cmd_path, F_OK) == -1)
	{
		free_two_dim(path);
		free(cmd_path);
		if (failed)
			exit(1);
		print_error(cmd);
	}
	return (cmd_path);
}

void	execute_command(t_data data, int fd[2])
{
	char	*cmd_path;

	cmd_path = find_command_path(data.cmd1, data.path);
}
