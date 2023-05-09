/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:18:02 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 15:27:57 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	duplicate_standard_file_descriptor(int in_fd, int out_fd)
{
	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
		print_error_by_errno();
}

void	close_file_descriptor(int fd)
{
	if (close(fd) == -1)
		print_error_by_errno();
}

void	close_pipe(int fildes[2])
{
	close_file_descriptor(fildes[READ]);
	close_file_descriptor(fildes[WRITE]);
}

void	open_pipe(int fildes[2])
{
	if (pipe(fildes) == -1)
		print_error_by_errno();
}
