#include "../../minishell.h"
#include <string.h>

t_global g_global;

int	main(int argc, char *argv[], char *envp[])
{
	t_node	*cd;
	t_node	*unset;

	init_envp(envp);
	
	cd = malloc(sizeof(t_node));
	cd->type = COMMAND;
	cd->arg_cnt = 2;
	cd->command_arg = malloc(sizeof(char *) * (cd->arg_cnt + 1));
	cd->command_arg[0] = strdup("cd");
	cd->command_arg[1] = strdup("../../.");
	cd->command_arg[2] = 0;

	ft_cd(cd);
	ft_pwd();
	ft_cd(cd);
	ft_pwd();
}
