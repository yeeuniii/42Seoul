/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:40:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/15 17:23:47 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
}
//
//void	f_del(void *content)
//{
//	free(content);
//	printf("free~\n");
//}
//
//int	main(void)
//{
//	t_list *l = ft_lstnew(ft_strdup("nyancat"));
//	l->next = ft_lstnew(ft_strdup("#TEST#"));
//
//	ft_lstclear(&l, f_del);
//}
