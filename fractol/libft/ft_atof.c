#include "libft.h"
#include <math.h>

static int	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

static void	calculate(const char **str, double *dst)
{
	(*dst) *= 10;
	(*dst) += **str - '0';
	(*str)++;
}

double	ft_atof(const char *nptr)
{
	int		sign;
	int		digit;
	double	res;
	double	tmp;

	sign = 1;
	digit = 0;
	tmp = 0;
	res = 0;
	if (ft_issign(*nptr))
	{
		sign = (*nptr == '+') - (*nptr == '-');
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '.')
		calculate(&nptr, &res);
	if (*nptr == '.')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		calculate(&nptr, &tmp);
		digit--;
	}
	res += tmp * pow(10, digit);
	return (res * sign);
}
//
//#include <stdio.h>
//
//int	main(void)
//{	
//	printf("----common_case----\n");
//	printf("%f\n", ft_atof("12.34"));
//	printf("%f\n", ft_atof("-12.34"));
//	printf("%f\n", ft_atof("+12.34"));
//
//	printf("----special_case----\n");
//	printf(".12 : %f\n", ft_atof(".12"));
//	printf("12. : %f\n", ft_atof("12."));
//	printf("%f\n", ft_atof("12.31.3df"));
//	printf("%f\n", ft_atof("12..31.3df"));
//	printf("%f\n", ft_atof("1212.12351235123"));
//
//	printf("----null_case----\n");
//	printf("%f\n", ft_atof("abc1231.12"));
//}
