#include <stdio.h>
#include <unistd.h>
#include "printf.h"
#include "libft/libft.h"

int	sum(int num, ...)
{
	va_list	ap;
	int	value;
	int	total;

	va_start(ap, num);
	total = 0;
	while (num --)
	{
		value = va_arg(ap, int);
		total += value;
	}
	return (total);
}

int	main(void)
{
	int	a = 1, b = 2, c = 3, d = 4;
	printf("%d\n", sum(10, a, b, c));
}
