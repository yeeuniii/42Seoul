/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:05:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 21:43:33 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include "execute_bonus.h"
# include "get_next_line.h"
# include "../libft/includes/libft.h"

# define NO_AUTH 0
# define NOT_COMMAND 1

# define OLD 0
# define NEW 1
# define READ 0
# define WRITE 1

typedef struct s_data
{
	int		here_doc;
	char	*limiter;
	char	*infile;
	char	*outfile;
	char	**cmds;
	int		cmd_num;
	char	**envp;
}	t_data;

void	process_data(int argc, char *argv[], char *envp[], t_data *data);
void	process_command(t_data data);
void	process_here_doc(t_data data);

int		process_first_command(int pipe[2][2], t_data data);
int		process_last_command(int pipe[2][2], t_data data);
int		process_other_command(int pipe[2][2]);

void	duplicate_standard_file_descriptor(int in_fd, int out_fd);
void	close_file_descriptor(int fd);
void	open_pipe(int fildes[2]);
void	close_pipe(int fildes[2]);

void	print_usage(int argc, char *argv[]);
void	print_error(char *file_name, int mode);
void	print_error_by_errno(void);
void	free_two_dim(char **str);

#endif
