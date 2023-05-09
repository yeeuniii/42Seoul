#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	str[10];
	int		fd2;
	fd = open("a.txt", O_RDWR);
	fd2 = dup2(fd, 1);
	printf("fd2 %d\n", fd2);
	
	write(fd2, "write\n", 6);
	fd2 = open("a.txt", O_RDWR);
	read(fd2, str, 6);
	printf("str : %s\n", str);
}
