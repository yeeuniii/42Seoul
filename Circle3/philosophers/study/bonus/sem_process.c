#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t	*sem;
int		num = 0;

void	*run(void *arg)
{
	sem_wait(sem);
	num = 5;
	printf("in monitor thread : %d\n", num);
	sem_post(sem);
	return (0);
}

int	main(void)
{
	pid_t		pid;
	pthread_t	monitor;

	sem_unlink("sem");
	sem = sem_open("sem", O_CREAT | O_EXCL, 0644, 1);
	pid = fork();
	if (pid < 0)
		return (printf("fork error\n"));
	if (pid == 0)
	{
		sem_wait(sem);
		num = 3;
		printf("in child process : %d\n", num);
		sem_post(sem);
		exit(0);
	}
	if (pid > 0)
	{
		pthread_create(&monitor, 0, run, 0);
		pthread_join(monitor, 0);
		printf("finish monitor thread\n");
		wait(&pid);
		printf("finish child process\n");
	}
	printf("finish main process\n");
	sem_close(sem);
	sem_unlink("sem");
	return (0);
}
