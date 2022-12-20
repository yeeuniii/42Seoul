/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:59 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/20 15:42:44 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_all(t_table table)
{
	if (table.philos)
		free(table.philos);
	if (table.forks)
		free(table.forks);
	if (table.forks_mutex)
		free(table.forks_mutex);
}

int	allocate_table(t_table *table)
{
	int		fail_allocation;
	int		number_of_philos;

	fail_allocation = 0;
	number_of_philos = (table->data).number_of_philos;
	table->philos = malloc(sizeof(t_philosopher) * number_of_philos);
	memset(table->philos, 0, sizeof(t_philosopher) * number_of_philos);
	if (!table->philos)
		fail_allocation = 1;
	table->forks = malloc(sizeof(int) * number_of_philos);
	memset(table->forks, 0, sizeof(int) * number_of_philos);
	if (!table->forks)
		fail_allocation = 1;
	table->forks_mutex = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (!table->forks_mutex)
		fail_allocation = 1;
	if (fail_allocation)
		free_all(*table);
	return (!fail_allocation);
}

void	init_mutex(t_table *table)
{
	int	idx;
	int	is_fail;

	idx = 0;
	is_fail = 0;
	while (!is_fail && idx < (table->data).number_of_philos)
	{
		is_fail= pthread_mutex_init(table->forks_mutex + idx, NULL);
		idx ++;
	}
}

void	set_fork(t_philosopher *philo, int number_of_philos)
{
	philo->left_fork = philo->number - 1;
	philo->right_fork = philo->number - 2;
	if (philo->number == number_of_philos)
		philo->left_fork = number_of_philos - 1;
	if (philo->number == 1)
		philo->right_fork = number_of_philos - 1;
}

void	join(t_table *table)
{
	int	idx;
	t_philosopher	*philo;

	idx = 0;
	while (idx < (table->data).number_of_philos)
	{
		philo = (table->philos) + idx;
		pthread_join(philo->thread, 0);
		idx ++;
	}
}

int	init_table(t_table *table)
{
	int				idx;
	t_philosopher	*philo;

	idx = 0;
	if (!allocate_table(table))
		return (0);
	init_mutex(table);
	gettimeofday(&(table->start_time), NULL);
	while (idx < (table->data).number_of_philos)
	{
		philo = table->philos + idx;
		philo->table = *table;
		philo->number = ++idx;
		philo->last_time_to_eat = 0;
		philo->is_died = 0;
		set_fork(philo, (table->data).number_of_philos);
	}
	
	idx = -1;
	while (++idx < (table->data).number_of_philos)
	{
		philo = table->philos + idx;
		pthread_create(&(philo->thread), 0, (void *)run, (void *)philo);
	}
	join(table);
	return (1);
}
