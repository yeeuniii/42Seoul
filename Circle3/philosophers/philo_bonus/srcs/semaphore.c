/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:14:35 by yeepark           #+#    #+#             */
/*   Updated: 2023/02/03 13:15:09 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	handle_duplicated_semaphore(t_semaphore *sem, int value, int *errno)
{
	if (sem_unlink(sem->name) == -1)
	{
		*errno = FAIL_SEMAPHORE_UNLINK;
		return ;
	}
	sem->sem = sem_open(sem->name, O_CREAT, 0644, value);
}

int	init_semaphore(t_semaphore *sem, char *name, int value, int *errno)
{
	sem->name = name;
	sem->sem = sem_open(sem->name, O_CREAT | O_EXCL, 0644, value);
	if (sem->sem == SEM_FAILED)
		handle_duplicated_semaphore(sem, value, errno);
	if (*errno && sem->sem == SEM_FAILED)
		*errno = FAIL_SEMAPHORE_OPEN;
	if (*errno)
		return (1);
	return (0);
}

void	clear_semapohre(t_semaphore sem, int *errno)
{
	if (*errno)
		return ;
	if (sem_close(sem.sem) == -1)
		*errno = FAIL_SEMAPHORE_CLOSE;
	if (sem_unlink(sem.name) == -1)
		*errno = FAIL_SEMAPHORE_UNLINK;
}

int	clear_all_semaphore(t_table *table, int number_of_philos, int *errno)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < number_of_philos)
	{
		philo = table->philos + idx;
		clear_semapohre(philo->sem_last_time, errno);
		clear_semapohre(philo->sem_eating, errno);
		idx++;
	}
	clear_semapohre(table->forks, errno);
	clear_semapohre(table->sem_message, errno);
	return (*errno);
}
