#include <stdio.h>

int	main(void)
{
	int	a = 5;
	int	c = a;
	int	*b = &a;

	a = 10;
	printf("a : %d\n", a);
	printf("b : %d\n", c);
	printf("c : %d\n", *b);
}
