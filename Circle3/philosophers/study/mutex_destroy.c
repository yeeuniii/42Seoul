#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	main(void)
{
	pthread_mutex_t		mutex;

//	pthread_mutex_init(&mutex, 0);
	pthread_mutex_destroy(&mutex);
	return (0);
}
