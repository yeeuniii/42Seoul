/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:15:30 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 20:17:37 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_file_authority(char *file_path, char *auth)
{
	if (*auth == 'f' && access(file_path, F_OK) == -1)
		print_error(file_path);
	if (*auth == 'f')
		auth++;
	if (*auth == 'r' && access(file_path, R_OK) == -1)
		print_error(file_path);
	if (*auth == 'r')
		auth++;
	if (*auth == 'w' && access(file_path, W_OK) == -1)
		print_error(file_path);
}

char	**find_path(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	return (ft_split(*envp + 5, ':'));
}

void	process_data(int argc, char *argv[], char **envp, t_data *data)
{
	if (argc != 5)
	{
		write(2, "usage : ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(1);
	}
	data->file1 = argv[1];
	check_file_authority(data->file1, "fr");
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->file2 = argv[4];
	data->path = find_path(envp);
	if (!data->path)
		exit(1);
}
