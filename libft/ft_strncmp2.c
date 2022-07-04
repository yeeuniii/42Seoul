#include "libft.h"

#include <stdio.h>
int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && idx < size - 1)
		idx ++;
	return (s1[idx] - s2[idx]);
}

#include <string.h>

int	main(void)
{
	printf("str: %d \tft_str: %d\n", strncmp("hello", "hella", 4), ft_strncmp("hello", "hella", 4));
	printf("str: %d \tft_str: %d\n", strncmp("hello", "hella", 5), ft_strncmp("hello", "hella", 5));
	printf("str: %d \tft_str: %d\n", strncmp("hello", "he", 4), ft_strncmp("hello", "he", 4));
}
