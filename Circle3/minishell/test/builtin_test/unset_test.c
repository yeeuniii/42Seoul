#include "../../minishell.h"
#include <string.h>

t_global g_global;

void	ft_unset(t_node *node);

int	main(int argc, char *argv[], char *envp[])
{
	t_node	*node;
	int		idx = 0;

	init_envp(envp);
	node = malloc(sizeof(t_node));
	node->arg_cnt = 10;
	node->command_arg = malloc(sizeof(char *) * node->arg_cnt);
	node->command_arg[idx++] = strdup("unset");
	node->command_arg[idx++] = strdup("a");
	node->command_arg[idx++] = strdup("asdf*");
	node->command_arg[idx++] = strdup("_b");
	node->command_arg[idx++] = 0;

//	printf("\n\nsingle export\n\n");
//	node->arg_cnt = 1;
//	ft_export(node);
	
	printf("\n\na asdf* _b export\n\n");
	node->arg_cnt = 3;
	ft_export(node);
	
	printf("\n\nsingle export\n\n");
	node->arg_cnt = 1;
	ft_export(node);

//	printf("\n\nsingle unset\n\n");
//	node->arg_cnt = 1;
//	ft_unset(node);
	
	node->command_arg[3] = strdup("b");
	printf("\n\nunset\n\n");
	node->arg_cnt = 10;
	ft_unset(node);

//	printf("\n\nsingle export\n\n");
//	node->arg_cnt = 1;
//	ft_export(node);
	
	return (g_global.exit_status);
}
