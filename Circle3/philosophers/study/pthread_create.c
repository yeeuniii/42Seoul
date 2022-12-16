#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*sleep_thread(void *arg)
{
	int	i = -1;

	while (i++ < 10)
	{
		sleep(1);
		printf("thread.. %d\n", i);
	}
}

int	main(void)
{
	pthread_t	thread;

	pthread_create(&thread, 0, sleep_thread, NULL);
	printf("thread id : %lx\n", thread);
	sleep(3);
	printf("finish process\n");
	return (0);
}
