#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	idx;

	idx = 0;
	if (!size)
		return (ft_strlen(src));
	while (idx < size - 1 && src[idx])
	{
		dest[idx] = src[idx];
		idx ++;
	}
	dest[idx] = 0;
	return (ft_strlen(src));
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[20] = "hello";
	char	dest1[20] = "nice to meet you";
	char	dest2[20] = "nice to meet you";

//	printf("strlcpy: %d : %s\n", strlcpy(dest1, src, 6), dest1);
	printf("ft_strlcpy: %ld : %s\n", ft_strlcpy(dest2, src, 0), dest2);
}
