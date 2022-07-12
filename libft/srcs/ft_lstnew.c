/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:46:01 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 20:17:05 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list *));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

//int	main(void)
//{
//	t_list *lst = ft_lstnew("hi");
//	lst -> next = ft_lstnew("my");
//	lst -> next -> next = ft_lstnew("name");
//	int	idx = 0;
//	while (lst)
//	{
//		printf("%s\n", lst -> content);
//		lst = lst -> next;
//		idx ++;
//	}
//	printf("cnt : %d\t ", idx);
//}
