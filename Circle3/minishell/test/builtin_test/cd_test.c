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
	cd->command_arg[1] = strdup("test");
	cd->command_arg[2] = 0;

	unset = malloc(sizeof(t_node));
	unset->type = COMMAND;
	unset->arg_cnt = 3;
	unset->command_arg = malloc(sizeof(char *) * (unset->arg_cnt + 1));
	unset->command_arg[0] = strdup("unset");
	unset->command_arg[1] = strdup("OLDPWD");
	unset->command_arg[2] = strdup("PWD");
	unset->command_arg[3] = 0;

	ft_unset(unset);

	printf("\n\nunset OLDPWD\n\n");
	unset->arg_cnt = 1;
	ft_export(unset);

	ft_cd(cd);

	printf("\n\nafter cd test\n\n");
	cd->arg_cnt = 1;
	ft_export(cd);
}
