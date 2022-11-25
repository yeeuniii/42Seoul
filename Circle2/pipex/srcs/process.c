/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:22:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 23:08:28 by yeepark          ###   ########.fr       */
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

char	*find_command_path(char **cmds, char **envp)
{
	int		idx;
	char	*cmd_path;

	idx = 0;
	cmd_path = 0;
	while (idx >= 0 && envp[idx])
	{
		free(cmd_path);
		cmd_path = join_path_and_cmd(envp[idx], cmds[0]);
		if (!cmd_path)
			idx = -2;
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		idx++;
	}
//	free_two_dim(cmds);
//	free_two_dim(envp);
//	free(cmd_path);
	if (idx == -1)
		exit(1);
	print_error(cmds[0]);
	return (0);
}

void	execute_command(t_data data, char *cmd_path, char **commands)
{
	pid_t	pid;
	int		fd[2];
	int		f;
	char	buf[1000];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
	{	
//		free_two_dim(cmds);
//		free_two_dim(envp);
//		free(cmd_path);
		exit(1);
	}
	if (pid == 0)
	{
		fd[0] = open(data.file1, O_RDWR);
		dup2(fd[0], 0);
		close(fd[1]);
		execve(cmd_path, commands, data.envp);
	}
	if (pid > 0)
	{
		wait(&pid);
		free(cmd_path);
		free_two_dim(commands);
		write(1, "parant\n", 7);
		read(fd[0], buf, 30);
		printf("%s\n", buf);
	}
}

void	process_command(t_data data)
{
	char	*cmd_path;
	char	**commands;

	commands = ft_split(data.cmd1, ' ');
	if (!commands)
		exit(1);
	cmd_path = find_command_path(commands, data.envp);
	execute_command(data, cmd_path, commands);
}
