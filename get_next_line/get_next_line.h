#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(const char *s1);

#endif
