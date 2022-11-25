/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:46:40 by yeepark           #+#    #+#             */
/*   Updated: 2022/11/25 19:53:57 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	**path;
}	t_data;

char	**find_path(char **envp);
void	process_data(int argc, char *argv[], char **envp, t_data *data);

#endif
