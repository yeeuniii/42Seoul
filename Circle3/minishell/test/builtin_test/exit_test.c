#include "../../minishell.h"
#include <string.h>

t_global g_global;

int	main(void)
{
	t_node	*case1 = malloc(sizeof(t_node));
	t_node	*case2 = malloc(sizeof(t_node));
	t_node	*case3 = malloc(sizeof(t_node));

	pid_t	pid;
	pid = fork();
	if (pid == 0)
	{
		printf("==== case1 ====\nexit n\n\n");
		case1->arg_cnt = 2;
		case1->command_arg = malloc(sizeof(char *) * (case1->arg_cnt + 1));
		case1->command_arg[0] = strdup("exit");
		case1->command_arg[1] = strdup("123");
		case1->command_arg[2] = 0;
		ft_exit(case1);
	}

	wait(&pid);
	pid = fork();
	if (pid == 0)
	{
		printf("\n\n==== case2 ====\nexit many args\n\n");
		case2->arg_cnt = 4;
		case2->command_arg = malloc(sizeof(char *) * (case2->arg_cnt + 1));
		case2->command_arg[0] = strdup("exit");
		case2->command_arg[1] = strdup("1");
		case2->command_arg[2] = strdup("2");
		case2->command_arg[3] = strdup("3");
		case2->command_arg[4] = 0;
		ft_exit(case2);
	}

	wait(&pid);
	pid = fork();
	if (pid == 0)
	{
		printf("\n\n==== case3 ====\nexit string\n\n");
		case3->arg_cnt = 2;
		case3->command_arg = malloc(sizeof(char *) * (case3->arg_cnt + 1));
		case3->command_arg[0] = strdup("exit");
		case3->command_arg[1] = strdup("+asdf");
		case3->command_arg[2] = 0;
		ft_exit(case3);
	}
	
