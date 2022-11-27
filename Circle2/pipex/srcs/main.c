/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:43:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/27 20:36:07 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//void	leaks(void)
//{
//	system("leaks pipex");
//}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int		pipe_fd[2];

//	atexit(leaks);
	process_data(argc, argv, envp, &data);
	if (pipe(pipe_fd) == -1)
		exit(1);
	process_command(data, &pipe_fd);
	process_last_cmd(data, &pipe_fd);
	free_two_dim(data.envp);
	return (0);
}
