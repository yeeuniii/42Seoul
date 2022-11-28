/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:32:58 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/28 19:33:01 by yeepark          ###   ########.fr       */
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
