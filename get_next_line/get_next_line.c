/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:47:03 by yeepark           #+#    #+#             */
/*   Updated: 2022/08/05 17:45:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	check_read(int fd, char **buf)
{
	int		reading;

	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (0);
	reading = read(fd, *buf, BUFFER_SIZE);
	if (reading == -1 || !reading)
	{
		free(*buf);
		*buf = 0;
		return (0);
	}
	buf[0][BUFFER_SIZE] = 0;
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

char	*add_backup(char *buf, char **backup, int *found)
{
	char	*tmp;

	tmp = ft_strdup(*backup);
	if (!tmp)
	{
		*found = -1;
		free(buf);
		free(backup);
		return (NULL);	
	}
	free(*backup);
	*backup = 0;
	*backup = ft_strjoin(tmp, buf);
	if (!*backup)
	{
		*found = -1;
		free(buf);
		free(tmp);
		return (NULL);	
	}
	free(tmp);
	return (NULL);
}

char	*get_line(char *buf, char **backup, int *found)
{
	int		idx;
	char 	*line;
	char	*tmp;

	idx = find_newline_index(buf);
	if (idx == -1)
		return (add_backup(buf, backup, found));
	*found = 1;
	tmp = ft_strdup(*backup);
	if (!tmp)
	{
		*found = -1;
		free(buf);
		free(*backup);
		return (NULL);	
	}
	free(*backup);
	*backup = 0;
	*backup = malloc(sizeof(char) * (BUFFER_SIZE - idx));
	backup[0][BUFFER_SIZE - idx - 1] = 0;
	ft_strlcpy(*backup, buf + idx + 1, BUFFER_SIZE - idx);
	buf[idx + 1] = 0;
	line = malloc(sizeof(char) * (ft_strlen(*backup) + idx + 2));
	if (!line)
	{
		*found = -1;
		free(buf);
		free(*backup);
		free(tmp);
		return (NULL);
	}
	line = ft_strjoin(tmp, buf);
	return (line);
}

char	*get_next_line(int fd)
{
	int			found;
	char		*buf;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	found = 0;
	buf = 0;
	line = 0;
	if (!backup)
		backup = ft_strdup("");
	while (!found)
	{
		if (!check_read(fd, &buf) && !backup)
			return (NULL);
		line = get_line(buf, &backup, &found);
		if (!line && found == -1)
			return (NULL);
	}
	free(buf);
	return (line);
}

int	main(void)
{
	int	fd = open("a.txt", O_RDONLY);
//
//	char	*buf;
//	char	*backup;
//	backup = ft_strdup("");
//	check_read(fd, &buf);
//	printf("buf : %s\n", buf);
//	
//	int	idx = find_newline_index(buf);
//	printf("%d\n", idx);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
