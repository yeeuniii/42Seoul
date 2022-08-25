/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:47:14 by yeepark           #+#    #+#             */
/*   Updated: 2022/08/25 15:41:59 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	idx;

	if (!s)
		return (0);
	idx = 0;
	while (s[idx])
		idx ++;
	return (idx);
}

char	*ft_strjoin(char *s1, char *s2, size_t readsize)
{
	size_t	idx;
	size_t	len1;
	char	*str;

	len1 = ft_strlen(s1);
	str = malloc(sizeof(char) * (len1 + readsize + 1));
	if (!str)
		return (NULL);
	idx = 0;
	while (s1 && s1[idx])
	{
		str[idx] = s1[idx];
		idx ++;
	}
	while (s2 && idx - len1 < readsize)
	{
		str[idx] = s2[idx - len1];
		idx ++;
	}
	str[idx] = 0;
	free(s1);
	s1 = 0;
	return (str);
}

int	ft_free(char *str)
{
	free(str);
	str = 0;
	return (0);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->fd = fd;
	lst->backup = 0;
	lst->next = 0;
	return (lst);
}

t_list	*match_fd(int fd, t_list **lst)
{
	t_list	*front;
	t_list	*new;
	t_list	*tmp;

	if (!*lst)
	{
		*lst = ft_lstnew(fd);
		if (!*lst)
			return (NULL);
		return (*lst);
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->fd > fd)
			break ;
		front = tmp;
		tmp = tmp->next;
	}
	new = ft_lstnew(fd);
	if (!new)
		return (NULL);
	new->next = tmp;
	front->next = new;
	return (new);
}
