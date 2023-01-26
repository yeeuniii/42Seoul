#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_thread
{
	int			id;
	pthread_t	tid;
}	t_thread;

sem_t	*sem;
int		num = 0;

void	*routine(void *arg)
{
	t_thread	thread;
	int			idx = -1;

	thread = *(t_thread *)arg;
	printf("before wait\n");
	sem_wait(sem);
	while (++idx < 3)
	{
		printf("id %d : %d\n", thread.id, num++);
		sleep(1);
	}
	sem_post(sem);
	return (0);
}

int	main(void)
{
	t_thread	threads[4];
	int			idx = -1;
	int			ret;

	sem = sem_open("sem", O_CREAT | O_EXCL, 0644, 1);
	if (sem == SEM_FAILED)
	{
		printf("re open\n");
		sem = sem_open("sem", O_EXCL);
	}
	if (sem == SEM_FAILED)
		return (printf("semaphore open fail\n"));
	while (++idx < 4)
	{
		threads[idx].id = idx;
		ret = pthread_create(&threads[idx].tid, 0, routine, threads + idx);
		printf("thread create : %d\n", ret);
	}
	idx = -1;
	while (++idx < 4)
	{
		pthread_join(threads[idx].tid, 0);
	}
	sem_close(sem);
	sem_unlink("sem");
	return (0);
}
