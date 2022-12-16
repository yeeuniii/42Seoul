#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*sleep_thread(void *i)
{
	(*(int *)i) += 1;
	return (0);
}

int	main(void)
{
	int	i = -1;
	void		**return_value;
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, 0, sleep_thread, &i);
	pthread_create(&thread2, 0, sleep_thread, &i);
//	printf("thread1 id : %lx\n", thread1);
//	printf("thread2 id : %lx\n", thread2);
	pthread_join(thread1, return_value);
	pthread_join(thread2, return_value);
	printf("i : %d\n", i);
	return (0);
}
