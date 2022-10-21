/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:38:07 by yeepark           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/15 00:32:53 by yeeun            ###   ########.fr       */
=======
/*   Updated: 2022/09/15 12:54:18 by yeepark          ###   ########.fr       */
>>>>>>> a13a7debf8682bda64f2b0c21c68d1b145e42f63
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline_index(char *str)
{
	int	idx;

	if (!str)
		return (-1);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx ++;
	}
	return (-1);
}

int	find_newline(int fd, char **backup)
{
	char	*buf;
	int		readsize;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf[BUFFER_SIZE] = 0;
	while (find_newline_index(*backup) == -1)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == -1 || (readsize == 0 && !(*backup)))
			return (ft_free(buf));
		if (readsize == 0)
			break ;
		*backup = ft_strjoin(*backup, buf, readsize);
		if (!*backup)
			return (ft_free(buf));
	}
	ft_free(buf);
	return (1);
}

char	*update_backup(char *backup, int newline)
{
	char	*update;
	int		idx;
	int		size;

	size = ft_strlen(backup) - newline;
	update = malloc(sizeof(char) * (size + 1));
	if (!update)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		update[idx] = backup[newline + 1 + idx];
		idx ++;
	}
	update[idx] = 0;
	free(backup);
	backup = 0;
	return (update);
}

char	*get_line(char **backup)
{
	char	*line;
	int		idx;
	int		newline;

	idx = 0;
	newline = find_newline_index(*backup);
	if (newline == -1)
		newline = ft_strlen(*backup) - 1;
	line = malloc(sizeof(char) * (newline + 2));
	if (!line)
		return (NULL);
	while (idx <= newline)
	{
		line[idx] = backup[0][idx];
		idx ++;
	}
	line[idx] = 0;
	*backup = update_backup(*backup, newline);
	if (!(**backup))
	{
		free(*backup);
		*backup = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!find_newline(fd, &backup))
		return (NULL);
	return (get_line(&backup));
}
<<<<<<< HEAD

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd = open("txt/lines_around_10.txt", O_RDONLY);
	int	idx = 0;

	printf("%d : %s", idx, get_next_line(fd));
	
	system("leaks a.out");
	return (0);
}
=======
>>>>>>> a13a7debf8682bda64f2b0c21c68d1b145e42f63
