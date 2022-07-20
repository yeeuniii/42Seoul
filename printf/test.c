#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	c = 5;
	void	*p = &c;
	unsigned char	*s = p;

	conver_base()
	write(1, s, 16);
	printf("\n");
	printf("%p\n", p);
}


