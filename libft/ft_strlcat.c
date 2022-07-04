#include "libft.h"

size_t	strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	idx;

	if (ft_strlen(dest) >= size - 1)
		return (ft_strlen(src) + ft_strlen(dest));
	idx = 0;
	while (idx < size - 1 && src[idx])
	{
		dest[idx + ft_strlen(dest)] = src[idx]
		idx ++;
	}
	dest[idx] = 0;
	return (ft_strlen(src) + size);
}
