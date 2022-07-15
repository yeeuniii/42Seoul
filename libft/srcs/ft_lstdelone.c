/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:31:57 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/15 16:48:40 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
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
//	t_list	*lst = ft_lstnew(str);
//
//	ft_lstdelone(lst, f_del);
//}
