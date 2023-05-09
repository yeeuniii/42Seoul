/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:22:25 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/06 17:14:53 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

typedef struct s_execute
{
	char	*cmd_path;
	char	**cmd_vector;
	char	**env_path;
	int		is_command;
}	t_execute;

void		free_execute(t_execute execute, int is_error);
t_execute	set_execute(char **envp, char *cmd);

#endif
