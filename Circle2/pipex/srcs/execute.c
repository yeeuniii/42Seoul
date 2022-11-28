/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:22:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/28 19:23:06 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipe(int pipe_fd[2])
{
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
}

void	open_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		exit(1);
}

int	set_child_process_fd(int pipe_fd[2], int idx, t_data data)
{
	int		open_fileno;

	if (idx == 1)
	{
		open_fileno = open(data.file1, O_RDWR);
		if (open_fileno == -1)
			return (0);
		dup2(open_fileno, STDIN_FILENO);
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
		close_pipe(pipe_fd);
		return (1);
	}
	if (idx == data.cmd_num)
	{
		open_fileno = open(data.file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (open_fileno == -1)
			return (0);
		dup2(pipe_fd[READ], STDIN_FILENO);
		dup2(open_fileno, STDOUT_FILENO);
		close_pipe(pipe_fd);
		return (1);
	}
	dup2(pipe_fd[READ], STDIN_FILENO);
	dup2(pipe_fd[WRITE], STDOUT_FILENO);
	close_pipe(pipe_fd);
	return (1);
}

void	execute_command(t_data data, t_execute execute, int pipe_fd[2], int idx)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		free_execute(execute, 1);
	if (pid == 0)
	{
		if (!set_child_process_fd(pipe_fd, idx, data))
			free_execute(execute, 1);
		if (execve(execute.cmd_path, execute.cmd_vector, execute.env_path) == -1)
			exit(1);
	}
	if (pid > 0)
	{
		free_execute(execute, 0);
		if (waitpid(pid, &status, WNOHANG) == -1)
			exit(1);
		if (idx == data.cmd_num)
			close_pipe(pipe_fd);
	}
}

void	process_command(t_data data)
{
	t_execute	execute;
	int			idx;
	int			pipe_fd[2];

	idx = 0;
	open_pipe(pipe_fd);
	while (idx++ < data.cmd_num)
	{	
		execute = set_execute(data.envp, *data.cmds);
		printf("cmd_path : %s\n", execute.cmd_path);
		printf("cmd_vector : %s\n", execute.cmd_vector[0]);
		execute_command(data, execute, pipe_fd, idx);
		data.cmds++;
	}
}
