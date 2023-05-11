#include "../minishell.h"
#include <string.h>

t_global	g_global;

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_node	*tmp;

	init_global(envp);

	// (export asdf=asdf && env) && export | grep asdf
	// node (logical - root)
	node = malloc(sizeof(t_node));
	node->type = LOGICAL;
	node->logical_type = ROOT;
	node->right = malloc(sizeof(t_node));
	node->left = malloc(sizeof(t_node));
	
	// left node (logical - root)
	tmp = node->left;
	tmp->type = LOGICAL;
	tmp->logical_type = ROOT;
	tmp->right = malloc(sizeof(t_node));
	tmp->left = malloc(sizeof(t_node));

	//left left node (command - export asdf=asdf)
	tmp = tmp->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("export");
	tmp->command_arg[1] = strdup("asdf=uasdfafasdf");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = 0;

	//left right node (logical - &&)
	tmp = node->left->right;
	tmp->type = LOGICAL;
	tmp->logical_type = AND;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//left right left node (command - env)
	tmp = node->left->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 1;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("export");
	tmp->command_arg[1] = 0;
	tmp->right = 0;
	tmp->left = 0;

	//right node (logical - and)
	tmp = node->right;
	tmp->type = LOGICAL;
	tmp->logical_type = AND;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//right left node (command - export)
	tmp = node->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 1;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("export");
	tmp->command_arg[1] = 0;
	tmp->right = 0;
	tmp->left = 0;
//
//	//right right node (logical - pipe)
//	tmp = node->right->right;
//	tmp->type = LOGICAL;
//	tmp->logical_type = PIPE;
//	tmp->right = 0;
//	tmp->left = malloc(sizeof(t_node));
//
//	//right right left node (command - grep)
//	tmp = node->right->right->left;
//	tmp->type = COMMAND;
//	tmp->command_path = 0;
//	tmp->arg_cnt = 2;
//	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
//	tmp->command_arg[0] = strdup("grep");
//	tmp->command_arg[1] = strdup("asdf");
//	tmp->command_arg[2] = 0;
//	tmp->right = 0;
//	tmp->left = 0;

//	search_heredoc(node);
	search_tree(node);

	t_node	*export;

	// node (logical - root)
	export = malloc(sizeof(t_node));
	export->type = LOGICAL;
	export->logical_type = ROOT;
	export->right = 0;
	export->left = malloc(sizeof(t_node));
	
	tmp = export->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 1;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("export");
	tmp->command_arg[1] = 0;
	tmp->right = 0;
	tmp->left = 0;

//
//	printf("\n\n\n\n");
//	search_node(export);

	clear_env();
	return (0);
}
