/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:19:04 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 16:17:38 by yeepark          ###   ########.fr       */
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
	t_data	data;

//	atexit(leaks);
	if (process_data(argc, argv, &data))
		return (print_usage());
	if (init(&table, data))
		return (print_error_message());
//	create_thread(&table);
	return (0);
}
