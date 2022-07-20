#include "printf.h"

void	print_hexa(unsigned long long n, char type)
{
	char	*base;

	base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (n)
	{
		print_hexa(n / 16);
		ft_putchar_fd(base[n % 16], 1);
	}
}

void	print_memory(void	*p)
{
	unsigned long long	addr;

	addr = (unsigned long long)p;
	ft_putstr_fd("0x", 1);
	print_hexa(addr);
}


