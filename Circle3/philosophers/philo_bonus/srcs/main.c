/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:32 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 16:52:21 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	clear_semaphore(t_table *table, int number_of_philos, int *errno)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < number_of_philos)
	{
		philo = table->philos + idx;
		if (sem_close(philo->sem_last_time.sem) == -1
			|| sem_close(philo->sem_eating.sem) == -1)
			*errno = FAIL_SEMAPHORE_CLOSE;
		if (sem_unlink(philo->sem_last_time.name) == -1
			|| sem_unlink(philo->sem_eating.name) == -1)
			*errno = FAIL_SEMAPHORE_UNLINK;
		idx++;
	}
	if (sem_close(table->forks.sem) == -1
		|| sem_close(table->sem_message.sem) == -1)
		*errno = FAIL_SEMAPHORE_CLOSE;
	if (sem_unlink(table->forks.name) == -1
		|| sem_unlink(table->sem_message.name) == -1)
		*errno = FAIL_SEMAPHORE_UNLINK;
	return (*errno);
}

void	free_all(t_table *table, int number_of_philos)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < number_of_philos)
	{
		philo = table->philos + idx;
		free(philo->sem_last_time.name);
		free(philo->sem_eating.name);
		idx++;
	}
	free(table->philos);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_table	table;
	int		errno;

	atexit(leak);
	errno = 0;
	if (init_data(&data, argc, argv))
		return (print_usage());
	if (init_table(&table, data, &errno)
		|| init_philosopher(&table, data, &errno))
		return (print_error(errno));
	if (create_process(&table, data, &errno)
		|| finish_process(&table, data))
		return (print_error(errno));
	if (clear_semaphore(&table, data.number_of_philos, &errno))
		return (print_error(errno));
	free_all(&table, data.number_of_philos);
	return (0);
}
