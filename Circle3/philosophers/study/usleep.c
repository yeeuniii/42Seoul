#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	usleep(100);
	printf("end usleep\n");
	sleep(1);
	printf("end sleep\n");
}
