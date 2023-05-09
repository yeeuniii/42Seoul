/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:27 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/12 15:55:30 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	process_data(argc, argv, envp, &data);
	if (data.here_doc)
		process_here_doc(data);
	process_command(data);
	free_two_dim(data.envp);
	free(data.limiter);
	return (0);
}
