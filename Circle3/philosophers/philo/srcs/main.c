/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:19:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/20 14:29:38 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//void	leaks(void)
//{
//	system("leaks philo");
//}

int	main(int argc, char *argv[])
{
	t_table	table;

//	atexit(leaks);
	if (!process_data(argc, argv, &(table.data)))
		return (print_usage());
	if (!init_table(&table))
		return (print_error_message());
	return (0);
}
