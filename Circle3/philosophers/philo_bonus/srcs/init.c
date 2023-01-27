/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:45:43 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/27 15:20:35 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	init_semaphore(t_semaphore *sem, char *name, int value, int *errno)
{
	sem->name = name;
//	if (sem_unlink(sem->name) == -1)
//	{
//		*errno = FAIL_SEMAPHORE_UNLINK;
//		return (1);
//	}
	sem_unlink(sem->name);
	sem->sem = sem_open(sem->name, O_CREAT | O_EXCL, 0644, value);
	if (sem->sem == SEM_FAILED)
	{
		*errno = FAIL_SEMAPHORE_OPEN;
		return (1);
	}
	return (0);
}

int	init_table(t_table *table, t_data data, int *errno)
{
	table->is_end = 0;
	table->data = data;
	init_semaphore(&table->forks, "sem_fork", data.number_of_philos, errno);
	init_semaphore(&table->sem_end, "sem_end", 1, errno);
	init_semaphore(&table->sem_message, "sem_message", 1, errno);
	table->philos = malloc(sizeof(t_philosopher) * data.number_of_philos);
	if (!table->philos)
		free(table->philos);
	if (*errno)
		return (1);
	return (0);
}

int	init_philosopher(t_table *table, t_data data, int *errno)
{
	t_philosopher	*philo;
	int				idx;

	idx = 0;
	while (!*errno && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->id = ++idx;
		philo->last_time_to_eat = 0;
		philo->number_of_eating = 0;
		init_semaphore(&philo->sem_last_time, "sem_last", 1, errno);
		init_semaphore(&philo->sem_eating, "sem_eating", 1, errno);
	}
	if (*errno)
		return (1);
	return (0);
}
