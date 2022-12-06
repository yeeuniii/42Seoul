/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:33:08 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/06 17:17:10 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	duplicate_stdandard_fd(int in_fd, int out_fd, int pipe_fd[2])
{
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close_pipe(pipe_fd);
}

int	set_child_process_fd(int pipe_fd[2], int idx, t_data data)
{
	int		open_fileno;

	if (idx == 1)
	{
		open_fileno = open(data.file1, O_RDWR);
		if (open_fileno == -1)
			return (0);
		duplicate_stdandard_fd(open_fileno, pipe_fd[WRITE], pipe_fd);
		return (1);
	}
	open_fileno = open(data.file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (open_fileno == -1)
		return (0);
	duplicate_stdandard_fd(pipe_fd[READ], open_fileno, pipe_fd);
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
			exit(0);
		status = execve(execute.cmd_path, execute.cmd_vector, execute.env_path);
		if (status == -1)
			print_error_by_errno();
	}
	if (pid > 0)
	{
		free_execute(execute, 0);
//		if (wait(&status) == -1)
//		{
//			perror("errno : ");
//			print_error_by_errno();
//		}
		if (waitpid(pid, &status, WNOHANG) == -1)
			print_error_by_errno();
//		while (waitpid(pid, &status, WNOHANG) == 0)
//		{
//			if (wait(&status) == -1)
//				print_error_by_errno();
//		}
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
		execute_command(data, execute, pipe_fd, idx);
		data.cmds++;
	}
}
