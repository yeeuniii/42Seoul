/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:50:07 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 20:30:56 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
//	lst = &new;
}

//int	main(void)
//{
//	t_list	*lst = ft_lstnew("hello");
//	ft_lstadd_front(&lst, ft_lstnew("yeepark"));
//	while (lst)
//	{
//		printf("%s\n", lst -> content);
//		lst = lst ->next;
//	}
//
//	t_list	*lst = 0;
//	ft_lstadd_front(&lst, ft_lstnew("hi"));
//	printf("%s\n", lst->content);
//}
