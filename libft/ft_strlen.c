#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx ++;
	return (idx);
}
