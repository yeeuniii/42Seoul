/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:39:29 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/01 16:42:40 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
		write(2, "usage : ./pipex file1 cmd1 cmd2 ... cmdn file2\n", 47);
		exit(1);
	}
	check_file_authority(argv[1], F_OK | R_OK);
	data->file1 = argv[1];
	data->file2 = argv[argc - 1];
	data->cmds = argv + 2;
	data->cmd_num = argc - 3;
//	printf("file1 %s\n", data->file1);
//	printf("file2 %s\n", data->file2);
//	printf("cmd[0] %s\n", data->cmds[0]);
//	printf("cmd_num %d\n", data->cmd_num);
	data->envp = find_env_path(envp);
}
