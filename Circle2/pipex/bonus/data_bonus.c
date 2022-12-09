/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:17 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 21:23:00 by yeepark          ###   ########.fr       */
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
	print_usage(argc, argv);
	if (ft_strcmp(argv[1], "here_doc"))
	{
		data->here_doc = 0;
		data->limiter = 0;
		data->infile = argv[1];
		data->outfile = argv[argc - 1];
		data->cmds = argv + 2;
		data->cmd_num = argc - 3;
		data->envp = find_env_path(envp);
		return ;
	}
	data->here_doc = 1;
	data->limiter = ft_strjoin(argv[2], "\n");
	if (!data->limiter)
		print_error_by_errno();
	data->cmds = argv + 3;
	data->cmd_num = 2;
	data->infile = ".tmp";
	data->outfile = argv[5];
	data->envp = find_env_path(envp);
}
