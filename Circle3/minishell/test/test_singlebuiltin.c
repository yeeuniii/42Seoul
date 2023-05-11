#include "../minishell.h"
#include <string.h>

t_global	g_global;

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_node	*tmp;

	init_envp(envp);
	init_builtin_functions();
	// node (logical - root)
	node = malloc(sizeof(t_node));
	node->type = LOGICAL;
	node->right = 0;
	node->left = malloc(sizeof(t_node));

	//left node (command - export)
	tmp = node->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 1;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("export");
//	tmp->command_arg[1] = strdup("a=-a");
	tmp->command_arg[tmp->arg_cnt] = 0;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//left left node (redirect < infile)
	tmp = tmp->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = HERE_DOCUMENT;
	tmp->redirect_filename = strdup("eof");
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	tmp = tmp->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_INPUT;
	tmp->redirect_filename = strdup("infile");
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	tmp = tmp->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_OUTPUT;
	tmp->redirect_filename = strdup("asdf");
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));
	
	tmp = tmp->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = HERE_DOCUMENT;
	tmp->redirect_filename = strdup("eof");
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));
	
	tmp = tmp->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_OUTPUT;
	tmp->redirect_filename = strdup("a");
	tmp->right = 0;
	tmp->left = 0;

	search_tree(node);

	return (0);
}
