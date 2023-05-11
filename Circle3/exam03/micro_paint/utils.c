#include "micro_paint.h"

int ft_strlen(char *str)
{
	int	idx = 0;

	if (!str)
		return (0);
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	return (1);
}
