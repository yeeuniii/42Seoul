#include <unistd.h>

int	main(void)
{
	char	*arr[] = {"ls", "-l", NULL};
	char	*envp[10];
	
	envp[0] = "/usr/local/bin";
	envp[1] = "/usr/bin";
	execve("/bin/ls", arr, envp);
}
