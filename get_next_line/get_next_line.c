/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:04:20 by yeepark           #+#    #+#             */
/*   Updated: 2022/08/09 14:32:42 by yeeun            ###   ########.fr       */
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

int	update_backup(char **backup, char *buf, int reading)
{
	char	*tmp;

	if (!reading)
		return (1);
	tmp = ft_strdup(*backup);
	*backup = 0;
	free(*backup);
	if (!tmp)
		return (0);
	*backup = ft_strjoin(tmp, buf);
	free(tmp);
	if (!*backup)
		return (0);
	return (1);
}

int	check_read(int fd, char	**buf, char **backup)
{
	int	size;
	int	reading;

	size = BUFFER_SIZE;
	reading = 0;
	if (find_newline_index(*backup) == -1)
	{
		size = read(fd, *buf, BUFFER_SIZE);
		buf[0][size] = 0;
		reading = 1;
	}
	if ((size == -1 || size == 0) && !(**backup))
		return (0);
	if (!update_backup(backup, *buf, reading))
		return (0);
	return (1);
}

char	*get_line(char **backup)
{
	char	*line;
	char	*tmp;
	int		idx;

	idx = find_newline_index(*backup);
	tmp = ft_strdup(*backup);
	free(*backup);
	if (!tmp)
		return (NULL);
	*backup = ft_strdup(tmp + idx + 1);
	if (!*backup)
	{
		free(tmp);
		return (NULL);
	}
	tmp[idx + 1] = 0;
	line = ft_strdup(tmp);
	free(tmp);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*backup;

	line = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	if (!backup)
		backup = ft_strdup("");
	if (!backup)
		return (NULL);
	while (!line)
	{
		if (!(check_read(fd, &buf, &backup)))
			break ;
		if (find_newline_index(backup) == -1)
			continue ;
		line = get_line(&backup);
		if (!line)
			break ;
	}
	free(buf);
	return (line);
}

//int	main(void)
//{
//	int	fd = open("b.txt", O_RDONLY);
//	int	idx = 0;
//
//	while (idx < 150)
//	{
//		printf("%d : %s", idx, get_next_line(fd));
//		idx ++;
//	}
//	return (0);
//}
