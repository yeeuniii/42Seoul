/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:39:35 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/01 14:59:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	duplicate_stdandard_fd(int in_fd, int out_fd, int pipe_fd[][2])
{
	if (dup2(in_fd, STDIN_FILENO) == -1)
		exit(1);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		exit(1);
	close(pipe_fd[OLD][READ]);
}

int	set_child_process_fd(int pipe_fd[][2], int idx, t_data data)
{
	int		open_fileno;
	
	close(pipe_fd[OLD][WRITE]);
	if (idx == 1)
	{
		open_fileno = open(data.file1, O_RDWR);
		if (open_fileno == -1)
			return (0);
		duplicate_stdandard_fd(open_fileno, pipe_fd[NEW][WRITE], pipe_fd);
		return (1);
	}
	if (idx == data.cmd_num)
	{
		open_fileno = open(data.file2, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (open_fileno == -1)
			return (0);
		duplicate_stdandard_fd(pipe_fd[OLD][READ], open_fileno, pipe_fd);
		return (1);
	}
	duplicate_stdandard_fd(pipe_fd[OLD][READ], pipe_fd[NEW][WRITE], pipe_fd);
	close(pipe_fd[NEW][WRITE]);
	return (1);
}

void	execute_command(t_data data, t_execute execute, int pipe_fd[2][2], int idx)
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
		status = execve(execute.cmd_path, execute.cmd_vector, execute.env_path);
		if (status == -1)
			exit(1);
	}
	free_execute(execute, 0);
	if (waitpid(pid, &status, WNOHANG) == -1)
		exit(1);
	close_pipe(pipe_fd[OLD]);
	pipe_fd[OLD][0] = pipe_fd[NEW][0];
	pipe_fd[OLD][1] = pipe_fd[NEW][1];
//	printf("old : %d %d\n", pipe_fd[OLD][0], pipe_fd[OLD][1]);
}

void	process_command(t_data data)
{
	t_execute	execute;
	int			idx;
	int			pipe_fd[2][2];

	idx = 0;
	open_pipe(pipe_fd[OLD]);
	while (idx++ < data.cmd_num)
	{
		execute = set_execute(data.envp, *data.cmds);
		open_pipe(pipe_fd[NEW]);
		execute_command(data, execute, pipe_fd, idx);
	//printf("old : %d %d\n", pipe_fd[OLD][0], pipe_fd[OLD][1]);
		data.cmds++;
	}
	close_pipe(pipe_fd[NEW]);
	free_two_dim(execute.env_path);
}
