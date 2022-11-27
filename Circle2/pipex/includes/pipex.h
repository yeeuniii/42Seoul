/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:46:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/27 20:41:06 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define READ 0
# define WRITE 1

typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
}	t_data;

void	process_data(int argc, char *argv[], char **envp, t_data *data);

void	process_command(t_data data, int pipe_fd[][2]);
void	process_last_cmd(t_data data, int pipe_fd[][2]);

void	print_error(char *file_name);
void	free_two_dim(char **str);

#endif
