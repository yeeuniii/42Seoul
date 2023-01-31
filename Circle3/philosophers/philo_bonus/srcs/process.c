/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:32:07 by yeepark           #+#    #+#             */
/*   Updated: 2023/01/31 15:37:55 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	run_philo(t_philosopher *philo, t_table *table, t_data data)
{
	if (pthread_create(&philo->monitor, 0, run_monitor, (void *)philo))
		return (FAIL_THREAD_CREATE);
	if (philo->id % 2 == 0)
		ft_usleep(table, data.time_to_eat / 2);
	while (1)
	{
		ft_eat(philo, table, data.time_to_eat);
		ft_sleep(philo, table, data.time_to_sleep);
		ft_think(philo, table);
	}
	if (pthread_join(philo->monitor, 0))
		return (FAIL_THREAD_JOIN);
}

int	create_process(t_table *table, t_data data, int *errno)
{
	int				idx;
	t_philosopher	*philo;

	idx = -1;
	gettimeofday(&table->start_time, 0);
	while (!*errno && ++idx < data.number_of_philos)
	{
		philo = table->philos + idx;
		philo->pid = fork();
		if (philo->pid < -1)
			*errno = FAIL_PROCESS_CREATE;
		if (philo->pid == 0)
			*errno = run_philo(philo, table, data);
	}
	return (*errno);
}

void	kill_process(t_table *table, int number_of_philos)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < number_of_philos)
	{
		philo = table->philos + idx;
		kill(philo->pid, SIGKILL);
		idx++;
	}
}

int	finish_process(t_table *table, t_data data)
{
	int	idx;
	int	status;

	idx = 0;
	while (idx < data.number_of_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			kill_process(table, data.number_of_philos);
			return (0);
		}
		idx++;
	}
	kill_process(table, data.number_of_philos);
	printf(EATING_ENOUGH_MSG);
	return (0);
}
