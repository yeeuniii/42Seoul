/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:38:53 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/01 16:43:27 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	print_error(char *file_name)
{
	write(2, file_name, ft_strlen(file_name));
	perror(" ");
	exit(1);
}

//void	print_error(char *file_name, int mode)
//{
//	if (!file_name)
//		return ;
//	if (mode == NO_FILE)
//	{
//		write(2, file_name, ft_strlen(file_name));
//		perror(" ");
//	}
//	if (mode == FAIL_MALLOC)
//		write(2, "fail malloc")
//	exit(1);
//}

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
