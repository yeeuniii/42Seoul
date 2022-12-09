/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:17 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 17:30:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	**find_env_path(char *envp[])
{
	char	**env_path;

	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		envp++;
	env_path = ft_split(*envp + 5, ':');
	if (!env_path)
		print_error_by_errno();
	return (env_path);
}

void	process_data(int argc, char *argv[], char *envp[], t_data *data)
{
	if (argc < 5)
	{
		write(2, "usage : ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(1);
	}
	data->file1 = argv[1];
	data->file2 = argv[argc - 1];
	data->cmds = argv + 2;
	data->cmd_num = argc - 3;
	data->envp = find_env_path(envp);
}
