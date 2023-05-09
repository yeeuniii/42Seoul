#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t		mutex;
pthread_mutex_t		mutex1;

void	*sleep_thread(void *i)
{
	pthread_mutex_lock(&mutex);
	(*(int *)i) += 1;
	pthread_mutex_unlock(&mutex);
	return (0);
}

int	main(void)
{
	int	i = 2;
	void		**return_value;
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_mutex_init(&mutex, 0);
	pthread_mutex_init(&mutex1, 0);
	printf("mutex id : %lx\n", mutex);
	printf("mutex1 id : %lx\n", mutex1);
	pthread_create(&thread1, 0, sleep_thread, &i);
	pthread_create(&thread2, 0, sleep_thread, &i);
	pthread_join(thread1, return_value);
	pthread_join(thread2, return_value);
	printf("i : %d\n", i);
	return (0);
}
