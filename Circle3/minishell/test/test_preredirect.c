#include "../minishell.h"
#include <string.h>

t_global	g_global;

int	main(int argc, char **argv, char **envp)
{
	t_node	*node;
	t_node	*tmp;

	init_global(envp);

	// (cat < infile && wc -l > outfile) > outfile << eof 
	// node (logical - root)
	node = malloc(sizeof(t_node));
	node->type = LOGICAL;
	node->logical_type = ROOT;
	node->right = 0;
	node->left = malloc(sizeof(t_node));
	node->pre_redirect = 0;

	// left node (logical - root)
	tmp = node->left;
	tmp->type = LOGICAL;
	tmp->logical_type = ROOT;
	tmp->right = malloc(sizeof(t_node));
	tmp->left = malloc(sizeof(t_node));
	tmp->pre_redirect = malloc(sizeof(t_node));	

	// left pre_redir node (> eof)
	tmp = node->left->pre_redirect;
	tmp->type = REDIRECT;
	tmp->redirect_type = HERE_DOCUMENT;
	tmp->redirect_filename = strdup("eof");
	tmp->in_fd = 0;
	tmp->out_fd = 1;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));
	tmp->pre_redirect = 0;

	// left pre_redir node (> eof)
	tmp = node->left->pre_redirect->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_OUTPUT;
	tmp->redirect_filename = strdup("outfile");
	tmp->in_fd = 0;
	tmp->out_fd = 1;
	tmp->right = 0;
	tmp->left = 0;
	tmp->pre_redirect = 0;
	
	//left left node (command - cat)
	tmp = node->left->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 1;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("cat");
	tmp->command_arg[1] = 0;
	tmp->right = 0;
//	tmp->left = malloc(sizeof(t_node));
	tmp->left = 0;
	tmp->pre_redirect = 0;

	// left left left  node (< infile)
//	tmp = tmp->left;
//	tmp->type = REDIRECT;
//	tmp->redirect_type = REDIRECTING_INPUT;
//	tmp->redirect_filename = strdup("infile");
//	tmp->in_fd = 0;
//	tmp->out_fd = 1;
//	tmp->right = 0;
//	tmp->left = 0;
//	tmp->pre_redirect = 0;
	
	//left right node (logical - &&)
	tmp = node->left->right;
	tmp->type = LOGICAL;
	tmp->logical_type = AND;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));
	tmp->pre_redirect = 0;

	//left right left node (command - ls -al)
	tmp = node->left->right->left;
	tmp->type = COMMAND;
	tmp->command_path = 0;
	tmp->arg_cnt = 2;
	tmp->command_arg = malloc(sizeof(char *) * (tmp->arg_cnt + 1));
	tmp->command_arg[0] = strdup("wc");
	tmp->command_arg[1] = strdup("-l");
	tmp->command_arg[2] = 0;
	tmp->right = 0;
	tmp->left = malloc(sizeof(t_node));
	tmp->pre_redirect = 0;

	// left right left left node (< a)
	tmp = tmp->left;
	tmp->type = REDIRECT;
	tmp->redirect_type = REDIRECTING_OUTPUT;
	tmp->redirect_filename = strdup("a");
	tmp->in_fd = 0;
	tmp->out_fd = 1;
	tmp->right = 0;
	tmp->left = 0;
	tmp->pre_redirect = 0;
	
	search_heredoc(node);
	search_tree(node);

	clear_env();
	return (0);
}
