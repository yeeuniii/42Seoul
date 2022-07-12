/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:52:06 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/12 20:48:34 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	if (!*lst)
		*lst = new;
}

//int	main(void)
//{
//	t_list	*lst = ft_lstnew("hi");
//	t_list	*lst = 0;
//	ft_lstadd_back(&lst, ft_lstnew("hello"));
//	printf("%s\n", lst -> content);
//	while (lst)
//	{
//		printf("%s\n", lst -> content);
//		lst = lst -> next;
//	}
//}
