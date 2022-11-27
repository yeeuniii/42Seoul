/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:22:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/27 21:32:51 by yeepark          ###   ########.fr       */
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

void	execute_command(t_data data, char *cmd_path, char **commands, int pipe_fd[][2])
{
	pid_t	pid;
	int		open_fileno;
	int		status;
	int		*fd;

	fd = *pipe_fd;
	open_fileno = open(data.file1, O_RDWR);
	if (open_fileno == -1)
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
		close(fd[READ]);
		dup2(open_fileno, STDIN_FILENO);
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
		if (execve(cmd_path, commands, data.envp) == -1)
			exit(1);
	}
	if (pid > 0)
	{
		free(cmd_path);
		free_two_dim(commands);
		if (waitpid(pid, &status, WNOHANG) == -1)
			exit(1);
		close(fd[WRITE]);
	//	dup2(fd[READ], STDIN_FILENO);
//		char *argv[3];
//		argv[0] = "wc";
//		argv[1] = "-l";
//		argv[2] = 0;
//		execve("/usr/bin/wc", argv, data.envp);
	}
}

void	make_output_file(t_data data, char *cmd_path, char **commands, int pipe_fd[][2])
{
	pid_t	pid;
	int		output_fileno;
	int		status;
	int		*fd;

	fd = *pipe_fd;
	output_fileno = open(data.file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (output_fileno == -1)
		exit(1);
//	if (access(data.file2, R_OK) == -1)
//		print_error(data.file2);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
//		printf("cmd_path %s\n", cmd_path);
//		printf("cmds[0] : %s\n", commands[0]);
		dup2(fd[READ], 0);
		dup2(output_fileno, 1);
		if (execve(cmd_path, commands, data.envp) == -1)
			exit(1);
	}
	if (pid > 0)
	{
		free(cmd_path);
		free_two_dim(commands);
		if (waitpid(pid, &status, WNOHANG) == -1)
			exit(1);
		close(fd[WRITE]);
	}
}

void	process_command(t_data data, int pipe_fd[][2])
{
	char	**commands;
	char	*cmd_path;

	commands = ft_split(data.cmd1, ' ');
	if (!commands)
		exit(1);
	cmd_path = find_command_path(commands, data.envp);
	execute_command(data, cmd_path, commands, pipe_fd);
}

void	process_last_cmd(t_data data, int pipe_fd[][2])
{
	char	**commands;
	char	*cmd_path;

	commands = ft_split(data.cmd2, ' ');
	if (!commands)
		exit(1);
	cmd_path = find_command_path(commands, data.envp);
	make_output_file(data, cmd_path, commands, pipe_fd);
}
