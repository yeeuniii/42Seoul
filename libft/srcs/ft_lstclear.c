/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:40:56 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 20:53:04 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		del(ptr->content);
		free(ptr);
		ptr = ptr->next;
	}
}

//void	f_del(void *content)
//{
//	free(content);
//	printf("free~\n");
//}
//
//int	main(void)
//{
//	char	*str = ft_strdup("hello");
//	char	*str1 = ft_strdup("hello");
//	t_list	*lst = ft_lstnew(str);
//	ft_lstadd_back(&lst, ft_lstnew(str1));
//
//	ft_lstclear(&lst, f_del);
//}
