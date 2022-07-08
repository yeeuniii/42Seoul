/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:53:42 by yeepark           #+#    #+#             */
/*   Updated: 2022/07/06 21:47:20 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

//#include <stdio.h>
//#include <ctype.h>
//
//int	main(void)
//{
//	int	idx = -5;
//	while (idx < 150)
//	{
//		printf("idx %d : ft  %d  is %d\n",idx, ft_isascii(idx), isascii(idx));
//		idx ++;
//	}
//}
