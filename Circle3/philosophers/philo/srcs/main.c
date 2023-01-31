/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:14:58 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 16:20:41 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_table	table;
	int		errno;

	errno = 0;
	if (init_data(&data, argc, argv))
		return (print_usage());
	if (init_table(&table, data, &errno)
		|| init_philosopher(&table, data, &errno))
		return (print_error(errno));
	if (create_thread(&table, data, &errno)
		|| wait_thread(&table, data, &errno))
		return (print_error(errno));
	free_all(&table, data.number_of_philos);
	return (0);
}
