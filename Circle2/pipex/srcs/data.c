/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:21:41 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 19:55:22 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	if (argc != 5)
	{
		ft_putstr_fd("usage : ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(1);
	}
	data->infile = argv[1];
	data->outfile = argv[4];
	data->cmds = argv + 2;
	data->cmd_num = 2;
	data->envp = find_env_path(envp);
}
