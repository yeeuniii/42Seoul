/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:33:08 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/06 23:19:47 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	duplicate_stdandard_fd(int in_fd, int out_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
		print_error_by_errno();
}

int	set_child_process_fd(int pipe_fd[2], int idx, t_data data)
{
	int		open_fileno;

	if (idx != 1)
	{
		close(pipe_fd[WRITE]);
		open_fileno = open(data.file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (open_fileno == -1)
			return (0);
		duplicate_stdandard_fd(pipe_fd[READ], open_fileno);
		close(pipe_fd[READ]);
		return (1);
	}
	close(pipe_fd[READ]);
	open_fileno = open(data.file1, O_RDWR);
	if (open_fileno == -1)
	{
		if (access(data.file1, F_OK | R_OK) == -1)
			print_error(data.file1, NO_AUTH);
		return (0);
	}
	duplicate_stdandard_fd(open_fileno, pipe_fd[WRITE]);
	close(pipe_fd[WRITE]);
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
		if (!execute.is_command)
			print_error(execute.cmd_vector[0], NOT_COMMAND);
		status = execve(execute.cmd_path, execute.cmd_vector, execute.env_path);
		if (status == -1)
			print_error_by_errno();
	}
	if (pid > 0)
		free_execute(execute, 0);
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
		execute_command(data, execute, pipe_fd, idx);
		data.cmds++;
	}
	close_pipe(pipe_fd);
	while (--idx)
	{
		if (wait(0) == -1)
			print_error_by_errno();
	}
}
