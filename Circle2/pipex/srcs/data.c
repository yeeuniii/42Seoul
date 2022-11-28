/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:21:41 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/28 18:11:20 by yeepark          ###   ########.fr       */
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
	char	**env_path;

	while (envp && *envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	env_path = ft_split(*envp + 5, ':');
	if (!env_path)
		exit(1);
	return (env_path);
}

void	process_data(int argc, char *argv[], char *envp[], t_data *data)
{
	if (argc < 5)
	{
		write(2, "usage : ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(1);
	}
	check_file_authority(argv[1], F_OK | R_OK);
	data->file1 = argv[1];
	data->file2 = argv[4];
	data->cmds = argv + 2;
	data->cmd_num = argc - 3;
	data->envp = find_env_path(envp);
}
