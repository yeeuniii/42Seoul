/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:50:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/12 15:50:40 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	process_here_doc(t_data data)
{
	char	*str;
	int		open_fileno;

	str = 0;
	open_fileno = open(data.infile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (ft_strcmp(data.limiter, str))
	{
		ft_putstr_fd(str, open_fileno);
		free(str);
		ft_putstr_fd("> ", 0);
		str = get_next_line(0);
		if (!str)
			print_error_by_errno();
	}
	free(str);
}

int	process_first_command(int pipe[2][2], t_data data)
{
	int	open_fileno;

	close_pipe(pipe[OLD]);
	close_file_descriptor(pipe[NEW][READ]);
	open_fileno = open(data.infile, O_RDWR);
	if (data.here_doc)
	{
		if (unlink(data.infile) == -1)
			print_error_by_errno();
	}
	if (open_fileno == -1)
	{
		if (access(data.infile, F_OK | R_OK) == -1)
			print_error(data.infile, NO_AUTH);
		return (0);
	}
	duplicate_standard_file_descriptor(open_fileno, pipe[NEW][WRITE]);
	close_file_descriptor(pipe[NEW][WRITE]);
	return (1);
}

int	process_last_command(int pipe[2][2], t_data data)
{
	int	mode;
	int	open_fileno;

	close_pipe(pipe[NEW]);
	close_file_descriptor(pipe[OLD][WRITE]);
	mode = O_RDWR | O_CREAT | O_TRUNC;
	if (data.here_doc)
		mode = O_RDWR | O_CREAT | O_APPEND;
	open_fileno = open(data.outfile, mode, 0644);
	if (open_fileno == -1)
		return (0);
	duplicate_standard_file_descriptor(pipe[OLD][READ], open_fileno);
	close_file_descriptor(pipe[OLD][READ]);
	return (1);
}

int	process_other_command(int pipe[2][2])
{
	close_file_descriptor(pipe[OLD][WRITE]);
	close_file_descriptor(pipe[NEW][READ]);
	duplicate_standard_file_descriptor(pipe[OLD][READ], pipe[NEW][WRITE]);
	close_file_descriptor(pipe[OLD][READ]);
	close_file_descriptor(pipe[NEW][WRITE]);
	return (1);
}
