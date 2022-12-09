/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:05:28 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/09 16:05:59 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_BONUS_H
# define EXECUTE_BONUS_H

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
