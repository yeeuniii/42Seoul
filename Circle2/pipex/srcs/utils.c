/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:17:18 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/27 20:01:44 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *file_name)
{
//	if (!file_name)
//		return ;
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
