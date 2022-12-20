#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char	*sleep_thread(void *arg)
{
	int	i = 0;
	char	*str = malloc(sizeof(char) * 3);
	while (i < 5)
	{
		sleep(1);
		printf("thread.. %d\n", i);
		i ++;
	}
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 0;
	return (str);
}

int	main(void)
{
	void		**return_value;
	pthread_t	thread;

	pthread_create(&thread, 0, (void *)sleep_thread, NULL);
	pthread_detach(thread);
//	printf("thread id : %lx\n", thread);
	sleep(3);
	printf("end sleep 3 in main thread\n");
	return (0);
}
