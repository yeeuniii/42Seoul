#include "../minishell.h"
#include <string.h>

t_global	g_global;

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

	//left node (command - yes)
	tmp = node->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("cat");
	tmp->command_arg[1] = strdup("/dev/random");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = 0;

	//right node (logical - pipe)
	tmp = node->right;
	tmp->type = LOGICAL;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//right left node (command - head -1)
	tmp = node->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("head");
	tmp->command_arg[1] = strdup("-1");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = 0;
	
	search_tree(node);
}
