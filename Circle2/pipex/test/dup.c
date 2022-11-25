#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(void)
{
	int	fd = open("a.txt", O_RDONLY);
	int	fd2 = open("b.txt", O_RDONLY);
	int	fd3;
	fd3 = dup2(fd, 4);

	printf("fd : %d fd2 : %d  fd3: %d\n", fd, fd2, fd3);
	printf("%s\n", get_next_line(fd2));

}
