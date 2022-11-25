/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:17:18 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 21:01:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *file_name)
{
	if (!*file_name)
		return ;
	write(2, file_name, ft_strlen(file_name));
	perror(": zsh");
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
