/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:33:08 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 15:24:40 by yeepark          ###   ########.fr       */
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
		print_error_by_errno();
	}
}

int	set_child_process(int pipe[2], int idx, t_data data)
{
	if (idx == 1)
		return (process_first_command(pipe, data.file1));
	return (process_last_command(pipe, data.file2));
}

void	execute_command(t_data data, t_execute execute, int pipe[2], int idx)
{
	pid_t	pid;
	int		error;

	pid = fork();
	if (pid == -1)
		free_execute(execute, 1);
	if (pid > 0)
		return ;
	if (!execute.is_command)
		print_error(execute.cmd_vector[0], NOT_COMMAND);
	if (!set_child_process(pipe, idx, data))
		free_execute(execute, 1);
	error = execve(execute.cmd_path, execute.cmd_vector, execute.env_path);
	if (error == -1)
		print_error_by_errno();
}

void	process_command(t_data data)
{
	t_execute	execute;
	int			idx;
	int			pipe[2];

	idx = 0;
	open_pipe(pipe);
	while (idx++ < data.cmd_num)
	{	
		execute = set_execute(data.envp, *data.cmds);
		execute_command(data, execute, pipe, idx);
		free_execute(execute, 0);
		data.cmds++;
	}
	close_pipe(pipe);
	while (--idx)
	{
		if (wait(0) == -1)
			print_error_by_errno();
	}
}
