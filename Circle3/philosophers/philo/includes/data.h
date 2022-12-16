/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:07:22 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/16 18:50:04 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <stdio.h>

typedef struct s_data
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_must_eat;
}	t_data;

int		process_data(int argc, char *argv[], t_data *data);
int		ft_atoi(const char *str);
void	print_usage(void);

#endif
