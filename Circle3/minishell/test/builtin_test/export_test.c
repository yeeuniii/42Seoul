#include "../../minishell.h"
#include <string.h>

t_global	g_global;

void	ft_env();

int	main(int argc, char *argv[], char *envp[])
{
	t_node	*node;

	init_envp(envp);
	node = malloc(sizeof(t_node));
	node->arg_cnt = 10;
	node->command_arg = malloc(sizeof(char *) * node->arg_cnt);
	node->command_arg[0] = strdup("export");
	node->command_arg[1] = strdup("PATH=/bin");
	node->command_arg[2] = strdup("a=11");
	node->command_arg[3] = strdup("asdf=`?asd/fasdf?-=asdf");
	node->command_arg[4] = strdup("b");
	node->command_arg[5] = strdup("?as");
	node->command_arg[6] = 0;

//	printf("env\n\n");
//	ft_env();
//	
//	printf("\n\nsingle_command\n\n");
//	node->arg_cnt = 1;
//	ft_export(node);
	
	printf("\n\nexport\n\n");
	ft_export(node);
	
	printf("\n\nafter export\n\n");
	node->arg_cnt = 1;
	ft_export(node);

	printf("\n\nenv\n\n");
	ft_env();
}

