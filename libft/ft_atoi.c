#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *string)
{
	int	idx;
	int	res;
	int	sign;

	idx = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(string[idx]))
		idx ++;
	if (string[idx] == '+' || string[idx] == '-')
	{
		sign = (string[idx] == '+') - (string[idx] == '-');
		idx ++;
	}
	while (ft_isdigit(string[idx]))
	{
		res = res * 10 + string[idx] - '0';
		idx ++;
	}
	return (res * sign);
}

//#include <stdio.h>
//int	main(void)
//{
//	printf("%d\n", ft_atoi(" \t  \n +130"));
//	printf("%d\n", ft_atoi("-0"));
//	printf("%d\n", ft_atoi("0"));
//	printf("%d\n", ft_atoi("2147483647"));
//	printf("%d\n", ft_atoi("-2147483648"));
//	printf("%d\n", ft_atoi("-214,7483648"));
//	printf("%d\n", ft_atoi("---+214,7483648"));
//	printf("%d\n", ft_atoi("abcde"));
//
//}
