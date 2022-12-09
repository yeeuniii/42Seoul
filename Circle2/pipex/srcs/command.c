/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:02:50 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 15:25:51 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	process_first_command(int pipe[2], char *file_name)
{
	int	open_fileno;

	close_file_descriptor(pipe[READ]);
	open_fileno = open(file_name, O_RDWR);
	if (open_fileno == -1)
	{
		if (access(file_name, F_OK | R_OK) == -1)
			print_error(file_name, NO_AUTH);
		return (0);
	}
	duplicate_standard_file_descriptor(open_fileno, pipe[WRITE]);
	close_file_descriptor(pipe[WRITE]);
	return (1);
}

int	process_last_command(int pipe[2], char *file_name)
{
	int	open_fileno;

	close_file_descriptor(pipe[WRITE]);
	open_fileno = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (open_fileno == -1)
		return (0);
	duplicate_standard_file_descriptor(pipe[READ], open_fileno);
	close_file_descriptor(pipe[READ]);
	return (1);
}
