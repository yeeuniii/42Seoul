/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:15:30 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/27 15:51:35 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_file_authority(char *file_path, int mode)
{
	if (access(file_path, mode) == -1)
		print_error(file_path);
}

char	**find_env_path(char *envp[])
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	return (ft_split(*envp + 5, ':'));
}

void	process_data(int argc, char *argv[], char *envp[], t_data *data)
{
	if (argc != 5)
	{
		write(2, "usage : ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(1);
	}
	data->file1 = argv[1];
	check_file_authority(data->file1, F_OK | R_OK);
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->file2 = argv[4];
	data->envp = find_env_path(envp);
	if (!data->envp)
		exit(1);
}
