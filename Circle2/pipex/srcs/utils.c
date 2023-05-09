/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:17:18 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 19:46:32 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
