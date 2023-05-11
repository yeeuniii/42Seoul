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
	t_node	*unset;
	t_node	*export;

	unset = malloc(sizeof(t_node));
	unset->type = COMMAND;
	unset->arg_cnt = 2;
	unset->command_arg = malloc(sizeof(char *) * (unset->arg_cnt + 1));
	unset->command_arg[0] = strdup("unset");
	unset->command_arg[1] = strdup("PATH");
	unset->command_arg[2] = 0;

	export = malloc(sizeof(t_node));
	export->type = COMMAND;
	export->arg_cnt = 2;
	export->command_arg = malloc(sizeof(char *) * (unset->arg_cnt + 1));
	export->command_arg[0] = strdup("export");
	export->command_arg[1] = strdup("PATH=/bin");
	export->command_arg[2] = 0;

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
	
	init_envp(envp);
	
	ft_unset(unset);

	search_heredoc(node);
	search_tree(node);

//	printf("exit_status : %d\n", g_global.exit_status);
	clear_env();
	return (g_global.exit_status);
}
