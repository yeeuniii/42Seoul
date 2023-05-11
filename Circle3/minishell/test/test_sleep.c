#include "../minishell.h"
#include <string.h>

t_global	g_global;

void	leak(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_node	*tmp;

	init_envp(envp);

	// node (logical - root)
	node = malloc(sizeof(t_node));
	node->type = LOGICAL;
	node->right = malloc(sizeof(t_node));
	node->left = malloc(sizeof(t_node));

	//left node (command - sleep 5)
	tmp = node->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("sleep");
	tmp->command_arg[1] = strdup("5");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = 0;

	//right node (logical - pipe)
	tmp = node->right;
	tmp->type = LOGICAL;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//right left node (command - sleep 3)
	tmp = node->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("sleep");
	tmp->command_arg[1] = strdup("10");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = 0;
	
	search_tree(node);

	return (g_global.exit_status);
}
