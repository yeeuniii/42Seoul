/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:39 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 20:09:02 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	print_usage(int argc, char *argv[])
{
	if (!ft_strcmp(argv[1], "here_doc") && argc != 6)
	{
		ft_putstr_fd("usage: ./pipex here_doc LIMITER cmd cmd1 file\n", 2);
		exit(1);
	}
	if (argc < 5)
	{
		ft_putstr_fd("usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
}

void	print_error(char *file_name, int mode)
{
	if (mode == NOT_COMMAND)
	{
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" : command not found\n", 2);
		exit(1);
	}
	if (mode == NO_AUTH)
	{
		ft_putstr_fd(file_name, 2);
		perror(" ");
		exit(1);
	}
}

void	print_error_by_errno(void)
{
	perror("");
	exit(1);
}

void	free_two_dim(char **str)
{
	int	idx;

	if (!str)
		return ;
	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx ++;
	}
	free(str[idx]);
	free(str);
}
