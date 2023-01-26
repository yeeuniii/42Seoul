/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:45:43 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/26 14:09:00 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	free_table(t_table *table)
{
	free(table->philos);
	return (1);
}

int	init_semaphore(t_semaphore *sem, char *name, int value)
{
	sem->name = name;
	sem_unlink(sem->name);
	sem->sem = sem_open(sem->name, O_CREAT | O_EXCL, 0644, value);
	if (sem->sem == SEM_FAILED)
		return (1);
	return (0);
}

int	init_table(t_table *table, t_data data)
{
	int	is_error;

	table->is_end = 0;
	table->philos = 0;
	table->data = data;
	is_error = init_semaphore(&table->forks, "sem_fork", data.number_of_philos);
	table->philos = malloc(sizeof(t_philosopher) * data.number_of_philos);
	if (!table->philos)
		is_error = 1;
	if (is_error)
	{
		free(table->philos);
		return (1);
	}
	return (0);
}

int	init_philosopher(t_table *table, t_data data)
{
	t_philosopher	*philo;
	int				idx;
	int				is_error;

	idx = 0;
	is_error = 0;
	while (!is_error && idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->id = ++idx;
		philo->last_time_to_eat = 0;
		philo->number_of_eating = 0;
		philo->delay = 0;
		is_error = (is_error
				|| init_semaphore(&philo->sem_last_time, "sem_last", 1)
				|| init_semaphore(&philo->sem_eating, "sem_eating", 1));
		//		|| init_semaphore(&philo->sem_delay, "sem_delay", 1));
	//printf("idx : %d is_err : %d\n", idx, is_error);
	}
	if (is_error)
	{
		printf("err\n");
		exit(1);
	}
	return (0);
}
