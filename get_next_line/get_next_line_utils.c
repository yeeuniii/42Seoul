#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx ++;
	return (idx);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		idx;
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		str[idx] = s1[idx];
		idx ++;
	}
	while (s2[idx])
	{
		str[idx] = s2[idx - len1];
		idx ++;
	}
	str[idx] = 0;
	return (str);
}

void    *ft_memmove(void *dst, const void *src, size_t len)
{
        size_t  idx;

        idx = 0;
        if (!dst && !src)
                return (0);
        if (dst <= src)
        {
                while (idx < len)
                {
                        *(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
                        idx ++;
                }
        }
        if (dst > src)
        {
                while (len --)
                        *(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
        }
        return (dst);
}

char    *ft_strdup(const char *s1)
{
        char    *dest;
        int             idx;

        dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
        if (!dest)
                return (0);
        idx = 0;
        while (s1[idx])
        {
                dest[idx] = s1[idx];
                idx ++;
        }
        dest[idx] = 0;
        return (dest);
}
