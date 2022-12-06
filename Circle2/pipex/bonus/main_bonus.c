/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:39:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/01 16:43:09 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
	return (0);
}
