#include "../includes/ft_printf.h"
#include <stdio.h>
int	main(void)
{
	char	c = 'a';
	
	printf("\n%%c\n");
	printf("%d\n", ft_printf("%c - ", c));
	printf("%d\n", printf("%c - ", c));
	
	char	*s = 0;
	
	printf("\n%%s\n");
	printf("%d\n", ft_printf("%s - ", s));
	printf("%d\n", printf("%s - ", s));
	
	int num = 50;
	int	min = -2147483648;

	printf("\n%%d\n");
	printf("%d\n", ft_printf("%d - ", num));
	printf("%d\n", printf("%d - ", num));
	
	printf("\n%%i\n");
	printf("%d\n", ft_printf("%i - ", min));
	printf("%d\n", printf("%i - ", min));
	
	int	u = -50;
	
	printf("\n%%u\n");
	printf("%d\n", ft_printf("%u\n", u));
	printf("%d\n", printf("%u\n", u));

	printf("\n%%p\n");
	printf("%d\n", ft_printf("%p\n", &num));
	printf("%d\n", printf("%p\n", &num));



	unsigned int x = 123456;
	
	printf("\n%%x\n");
	printf("%d\n", ft_printf("%x\n", x));
	printf("%d\n", printf("%x\n", x));
	printf("\n%%X\n");
	printf("%d\n", ft_printf("%X\n", x));
	printf("%d\n", printf("%X\n", x));

	int a1 = printf("%c aa %d aa %s aa %x aa %p aa \n", 'a', 'a', "abc", 123456, "a");
	int a2 = ft_printf("%c aa %d aa %s aa %x aa %p aa \n", 'a', 'a', "abc", 123456, "a");
	ft_printf ("\n%d %d\n\n", a1, a2 );

	ft_printf("%x %x %x \n", 512, 512, 512);
	ft_printf("%d %d %d \n", 512, 512, 512);
	ft_printf("%p %p %p \n", &a1, &a1, &a1);
}	

