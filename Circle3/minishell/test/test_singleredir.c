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
	node->right = 0;
	node->left = malloc(sizeof(t_node));
	
	//left node (command)
	tmp = node->left;
	tmp->type = COMMAND;
	tmp->command_arg = 0;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));	

	//left node (redir)
	tmp = node->left->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_OUTPUT;
	tmp->redirect_filename = strdup("outfile");
	tmp->in_fd = 0;
	tmp->out_fd = 1;
	tmp->right = 0;
	tmp->left = 0;

	search_tree(node);
	
	printf("end\n");
	return (0);
}
