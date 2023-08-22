#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define OLD 0
#define NEW 1
#define READ 0
#define WRITE 1

int ft_strlen(char *str)
{
	int idx = 0;

	if (!str)
		return 0;
	while (str[idx])
		idx++;
	return idx;
}

int	isSemicolon(char *c)
{
	if (!c)
		return 0;
	return strcmp(c, ";") == 0;
}

int	isPipe(char *c)
{
	if (!c)
		return 0;
	return strcmp(c, "|") == 0;
}

int	isSeperator(char *c)
{
	if (!c)
		return 0;
	return isPipe(c) || isSemicolon(c);
}

int	getNextIndex(char *argv[])
{
	int	idx = 0;

	while (argv[idx] && isSeperator(argv[idx]) == 0)
		idx++;
	return idx;
}

char	**getArgv(char *argv[])
{
	char	**newArgv;
	int		size = getNextIndex(argv);

	newArgv = malloc(sizeof(char *) * (size + 1));
	for (int idx = 0; idx < size; idx++)
		newArgv[idx] = argv[idx];
	newArgv[size] = 0;
	return newArgv;
}

void	printSystemError()
{
	char *errorMsg = "error: fatal\n";

	write(2, errorMsg, ft_strlen(errorMsg));
}

void	handleExecveError(int isError, char *path)
{
	char *errorMsg = "error: cannot execute ";

	if (isError == 0)
		return ;
	write(2, errorMsg, ft_strlen(errorMsg));
	write(2, path, ft_strlen(path));
	write(2, "\n", 1);
	exit(1);
}

void	ft_cd(char *argv[])
{
	int		size = getNextIndex(argv);
	char	*errorMsg = "error: cd: bad arguments\n";

	if (size != 2)
	{
		write(2, errorMsg, ft_strlen(errorMsg));
		return ;
	}
	if (chdir(argv[1]) == -1)
	{
		errorMsg = "error: cd: cannot change directory to ";
		write(2, errorMsg, ft_strlen(errorMsg));
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
	}
}

void	ft_wait(int *size)
{
	for (int idx = 0; idx < *size; idx++)
		wait(0);
	*size = 0;
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pp[2][2];
	int		idx = 1;
	int		size = 0;
	int		isError;
	pid_t	pid;

	pipe(pp[OLD]);	
	while (idx < argc)
	{
		if (isSemicolon(argv[idx]))
		{
			idx++;
			continue;
		}
		if (strcmp(argv[idx], "cd") == 0)
		{
			ft_cd(argv + idx);
			idx += getNextIndex(argv + idx) + 1;
			continue;
		}
		if (isSemicolon(argv[idx - 1]))
			ft_wait(&size);
		pipe(pp[NEW]);	
		pid = fork();
		size++;
		if (pid == -1)
		{
			printSystemError();
			size--;
		}
		if (pid == 0)
		{
			close(pp[OLD][WRITE]);
			close(pp[NEW][READ]);
			if (isPipe(argv[idx - 1]))
				dup2(pp[OLD][READ], STDIN_FILENO);
			if (isPipe(argv[idx + getNextIndex(argv + idx)]))
				dup2(pp[NEW][WRITE], STDOUT_FILENO);
			close(pp[OLD][READ]);
			close(pp[NEW][WRITE]);
			isError = execve(argv[idx], getArgv(argv + idx), envp);
			handleExecveError(isError, argv[idx]);
		}
		close(pp[OLD][WRITE]);
		close(pp[OLD][READ]);
		pp[OLD][READ] = pp[NEW][READ];
		pp[OLD][WRITE] = pp[NEW][WRITE];
		idx += getNextIndex(argv + idx) + 1;
	}
	ft_wait(&size);
	close(pp[OLD][WRITE]);
	close(pp[OLD][READ]);
	return 0;
}