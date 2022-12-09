/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 17:28:15 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	process_first_command(int pipe[2][2], char *file_name)
{
	int	open_fileno;

	close_pipe(pipe[OLD]);
	close_file_descriptor(pipe[NEW][READ]);
	open_fileno = open(file_name, O_RDWR);
	if (open_fileno == -1)
	{
		if (access(file_name, F_OK | R_OK) == -1)
			print_error(file_name, NO_AUTH);
		return (0);
	}
	duplicate_standard_file_descriptor(open_fileno, pipe[NEW][WRITE]);
	close_file_descriptor(pipe[NEW][WRITE]);
	return (1);
}

int	process_last_command(int pipe[2][2], char *file_name)
{
	int	open_fileno;

	close_pipe(pipe[NEW]);
	close_file_descriptor(pipe[OLD][WRITE]);
	open_fileno = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (open_fileno == -1)
		return (0);
	duplicate_standard_file_descriptor(pipe[OLD][READ], open_fileno);
	close_file_descriptor(pipe[OLD][READ]);
	return (1);
}

int	process_other_command(int pipe[2][2])
{
	close_file_descriptor(pipe[OLD][WRITE]);
	close_file_descriptor(pipe[NEW][READ]);
	duplicate_standard_file_descriptor(pipe[OLD][READ], pipe[NEW][WRITE]);
	close_file_descriptor(pipe[OLD][READ]);
	close_file_descriptor(pipe[NEW][WRITE]);
	return (1);
}
