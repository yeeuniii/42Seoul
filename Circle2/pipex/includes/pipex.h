/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:46:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/01 16:23:25 by yeepark          ###   ########.fr       */
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
# include "execute.h"
# include "../libft/includes/libft.h"

# define NO_AUTH 0
# define NOT_COMMAND 1

# define OLD 0
# define NEW 1
# define READ 0
# define WRITE 1

typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	**cmds;
	int		cmd_num;
	char	**envp;
}	t_data;

void	process_data(int argc, char *argv[], char *envp[], t_data *data);
void	process_command(t_data data);

void	open_pipe(int piep_fd[2]);
void	close_pipe(int pipe_fd[2]);

void	print_error(char *file_name, int mode);
void	print_error_by_errno(void);
void	free_two_dim(char **str);

#endif
