/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:15:30 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 19:53:45 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *file_name)
{
	write(2, file_name, ft_strlen(file_name));
	perror(": zsh");
	exit(1);
}

void	check_file_authority(char *file_name, char *auth)
{
	if (*auth == 'f' && access(file_name, F_OK) == -1)
		print_error(file_name);
	if (*auth == 'f')
		auth++;
	if (*auth == 'r' && access(file_name, R_OK) == -1)
		print_error(file_name);
	if (*auth == 'w' && access(file_name, W_OK) == -1)
		print_error(file_name);
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
