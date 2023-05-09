/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:45:43 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 16:03:23 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	init_table(t_table *table, t_data data, int *errno)
{
	init_semaphore(&table->forks, "sem_fork", data.number_of_philos, errno);
	init_semaphore(&table->sem_message, "sem_message", 1, errno);
	table->philos = malloc(sizeof(t_philosopher) * data.number_of_philos);
	if (!table->philos)
		free(table->philos);
	if (*errno)
		return (1);
	return (0);
}

char	*make_semaphore_name(char *name, int number)
{
	char	*des;
	int		len;
	int		idx;

	len = 0;
	idx = 0;
	while (name[len])
		len++;
	des = malloc(sizeof(char) * (len + 4));
	while (idx < len)
	{
		des[idx] = name[idx];
		idx++;
	}
	des[idx++] = number / 100 + '0';
	number %= 100;
	des[idx++] = number / 10 + '0';
	des[idx++] = number % 10 + '0';
	des[idx] = 0;
	return (des);
}

int	init_philosopher(t_table *table, t_data data, int *errno)
{
	t_philosopher	*philo;
	char			*name;
	int				idx;

	idx = 0;
	while (!*errno && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->id = ++idx;
		philo->last_time_to_eat = 0;
		philo->number_of_eating = 0;
		philo->table = table;
		philo->data = data;
		name = make_semaphore_name("sem_last", philo->id);
		init_semaphore(&philo->sem_last_time, name, 1, errno);
		name = make_semaphore_name("sem_eating", philo->id);
		init_semaphore(&philo->sem_eating, name, 1, errno);
	}
	if (*errno)
		return (1);
	return (0);
}
