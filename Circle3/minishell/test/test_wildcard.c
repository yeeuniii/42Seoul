#include "../../minishell.h"

t_global	g_global;


int	main(void)
{
//	printf("%d\n", is_wildcard_format("a.out", "*out*"));
//	printf("%d\n", is_wildcard_format("a.out", "*out"));
//	printf("%d\n", is_wildcard_format("a.out", "*"));
//	printf("%d\n", is_wildcard_format("a.out", "out*"));
//
//	printf("\n\n\n");

	t_node	*node = malloc(sizeof(t_node));
	
	node->arg_cnt = 2;
	node->command_arg = malloc(sizeof(char *) * (node->arg_cnt + 1));
	node->command_arg[0] = strdup("ls");
	node->command_arg[1] = strdup("*.c");
	node->command_arg[2] = 0;

	handle_wildcard(node);
	
	int	idx = 0;
	while (node->command_arg[idx])
	{
		printf("%s\n", node->command_arg[idx]);
		idx++;
	}

	system("leaks a.out");
	return (0);
}
