#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*sleep_thread(void *arg)
{
	int	i = -1;

	printf("%c\n", &arg);
	while (i++ < 10)
	{
		sleep(1);
		printf("thread.. %d\n", i);
	}
}

int	main(void)
{
	pthread_t	thread;
	char		*str = "hello world!";
	char		c = 'a';

	pthread_create(&thread, 0, sleep_thread, (void *)&c);
	printf("thread id : %lx\n", thread);
	sleep(3);
	printf("finish process\n");
	return (0);
}
