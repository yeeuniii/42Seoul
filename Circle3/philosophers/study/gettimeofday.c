#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int	main(void)
{
	struct timeval	start_time;
	struct timeval	end_time;
	double			difftime;

	gettimeofday(&start_time, NULL);
	printf("s : %ld\tms : %d\n", start_time.tv_sec, start_time.tv_usec);
//	usleep(100);
	sleep(1);
	gettimeofday(&end_time, NULL);
	printf("s : %ld\tms : %d\n", end_time.tv_sec, end_time.tv_usec);
	difftime = end_time.tv_sec - start_time.tv_sec + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
	printf("%lf s\n", difftime);
}
