/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeeun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:13:14 by yeeun             #+#    #+#             */
/*   Updated: 2022/08/05 02:06:26 by yeeun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	check_read(int fd, char **buf)
{
	int		reading;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	reading = read(fd, *buf, BUFFER_SIZE);
	if (reading == -1 || !reading)
	{
		free(*buf);
		*buf = 0;
		return (0);
	}
	buf[BUFFER_SIZE] = 0;
	return (reading);
}

int	find_newline_index(char *buf)
{
	int	idx;

	idx = 0;
	while (idx < BUFFER_SIZE)
	{
		if (buf[idx] == '\n')
			return (idx);
		idx ++;
	}
	return (-1);
}

char	*add_backup(char *buf, char **backup, int time, int *found)
{
	char	*tmp;

	tmp = ft_strdup(*backup);
	if (!tmp)
	{
		*found = -1;
		return (NULL);	
	}
	if (**backup)
	{
		free(*backup);
		*backup = 0;
	}
	*backup = ft_strjoin(tmp, buf);
	if (!*backup)
	{
		*found = -1;
		return (NULL);	
	}
	return (NULL);
}

char	*get_line(char *buf, char **backup, int time, int *found)
{
	int		idx;
	char 	*line;
	size_t	backup_size;
	size_t	size;

	idx = find_newline_index(buf);
	if (find_newline_index(buf) == -1)
		return (add_backup(buf, backup, time, found));
	*found = 1;
	backup_size = ft_strlen(*backup);
	size = backup_size + idx + 1;
	line = malloc(sizeof(char) * (size + 1));
	ft_memmove(line, *backup, backup_size);
	ft_memmove(line + backup_size, buf, idx + 1);
	line[size] = 0;
	if (**backup)
	{
		free(*backup);
		*backup = 0;
	}
	if (idx < BUFFER_SIZE - 1)
	{
		*backup = malloc(sizeof(char) * (BUFFER_SIZE - idx));
		ft_memmove(backup, buf + idx, BUFFER_SIZE - idx - 1);
		backup[BUFFER_SIZE - idx] = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int			time;
	int			found;
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	time = 0;
	line = 0;
	found = 0;
	while (!found)
	{
		if (check_read(fd, &buf))
			return (NULL);
		time ++;
		line = get_line(buf, &backup, time, &found);
		if (!line && found == -1)
			return (NULL);
	}
	return (line);
}

int	main(void)
{
	int	fd = open("a.txt", O_RDONLY);

	printf("%s\n",	get_next_line(fd));
	printf("%s\n",	get_next_line(fd));
	printf("%s\n",	get_next_line(fd));
}
