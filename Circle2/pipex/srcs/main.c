/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:43:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 19:53:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;
	int		fd[2];

	process_data(argc, argv, envp, &data);
	if (pipe(fd) == -1)
		exit(1);
	return (0);
}
