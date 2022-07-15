/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:32:51 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/15 12:13:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//int	main(void)
//{
//	t_list *lst = 0;
//	lst -> next = ft_lstnew("my");
//	lst -> next -> next = ft_lstnew("name");
//	
//	printf("%s", ft_lstlast(lst) -> content);
//}
