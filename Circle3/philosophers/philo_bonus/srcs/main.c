/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:32 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/26 12:20:59 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_table	table;

	if (init_data(&data, argc, argv))
		return (print_usage());
	if (init_table(&table, data) || init_philosopher(&table, data))
		return (printf("error\n"));
	create_process(&table, data);
	return (0);
}
