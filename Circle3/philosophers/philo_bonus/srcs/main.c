/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:32 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 10:46:11 by yeepark          ###   ########.fr       */
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
		print_error(errno);
	create_process(&table, data);
	return (0);
}
