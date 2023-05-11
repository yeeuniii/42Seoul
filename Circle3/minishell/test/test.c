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

	//left node (command - grep)
	tmp = node->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("grep");
	tmp->command_arg[1] = strdup("a");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//left left node (redirect << eof)
	tmp = node->left->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = HERE_DOCUMENT;
	tmp->redirect_filename = strdup("eof");
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//left left left node (redirect < infile)
	tmp = node->left->left->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_INPUT;
	tmp->redirect_filename = strdup("infile");
	tmp->right = 0;
	tmp->left = 0;

	//right node (logical - pipe)
	tmp = node->right;
	tmp->type = LOGICAL;
	tmp->right = malloc(sizeof(t_node));
	tmp->left = malloc(sizeof(t_node));

	//right left node (command - sort -u)
	tmp = node->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("sort");
	tmp->command_arg[1] = strdup("-u");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = 0;

	//right right node (logical - pipe)
	tmp = node->right->right;
	tmp->type = LOGICAL;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));

	//right right left node (command - cat)
	tmp = node->right->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 1;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("cat");
	tmp->command_arg[1] = 0;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));
	
	//right right left left node (redirect >> outfile)
	tmp = node->right->right->left->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = APPENDING_REDIRECTED_OUTPUT;
	tmp->redirect_filename = strdup("outfile");
	tmp->right = 0;
	tmp->left = 0;
	
	search_heredoc(node);
	search_tree(node);

	clear_env();
	return (0);
}
