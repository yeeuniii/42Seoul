#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>

typedef struct s_data
{
	pthread_t	thread;
	pid_t		pid;
	int			id;
	int			last_time;
}	t_data;

sem_t	*sem;

void	process(t_data *data, int idx)
{
	while (1)
	{
		usleep(1000 * 100);
		(data->last_time) += 100;
	}
}

void	*run(void *arg)
{
	t_data *data = (t_data  *)arg;
	int	before;

	while (1)
	{
//		if (before != data->last_time && data->id == 1)	
//			printf("last : %d\n", data->last_time);
		
		if (data->last_time >= 500)
		{
			sem_wait(sem);
			printf("id %d: last %d\n", data->id, data->last_time);
			kill(data->pid, SIGKILL);
			sem_post(sem);
		}
		before = data->last_time;
	}
	return (0);
}

int	main(void)
{
	t_data	data[4];
	int	idx = -1;

	sem_unlink("sem");
	sem = sem_open("sem", O_CREAT | O_EXCL, 0644, 1);
	while (++idx < 4)
	{
		data[idx].pid = fork();
		if (data[idx].pid > 0)
			continue;
		pthread_create(&data[idx].thread, 0, run, (void *)(data + idx));
		data[idx].id = idx;
		data[idx].last_time = 0;
		process(data + idx, idx);
		pthread_join(data[idx].thread, 0);
	}
	while (1){}
}
