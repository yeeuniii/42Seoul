/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:32 by yeepark           #+#    #+#             */
/*   Updated: 2023/02/03 13:14:13 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

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
	if (create_process(&table, data, &errno)
		|| finish_process(&table, data))
		return (print_error(errno));
	if (clear_all_semaphore(&table, data.number_of_philos, &errno))
		return (print_error(errno));
	free_all(&table, data.number_of_philos);
	return (0);
}
