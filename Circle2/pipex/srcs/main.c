/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:43:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 22:31:52 by yeepark          ###   ########.fr       */
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

//	atexit(leaks);
	process_data(argc, argv, envp, &data);
	process_command(data);
	free_two_dim(data.envp);
	return (0);
}
