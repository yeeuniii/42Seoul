/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:52:46 by yeepark           #+#    #+#             */
/*   Updated: 2022/12/22 17:10:30 by yeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_table(t_table table)
{
	free(table.philos);
	free(table.mutex_forks);
	free(table.forks);
}

int	allocate_table(t_table *table, int number_of_philos)
{
	int	fail_allocation;

	fail_allocation = 0;
	table->philos = 0;
	table->mutex_forks = 0;
	table->forks = 0;
	table->philos = malloc(sizeof(t_philosopher) * number_of_philos);
	if (!table->philos)
		fail_allocation = 1;
	table->mutex_forks = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (!table->mutex_forks)
		fail_allocation = 1;
	table->forks = malloc(sizeof(char) * number_of_philos);
	if (!table->forks)
		fail_allocation = 1;
	if (fail_allocation)
		free_table(*table);
	return (fail_allocation);
}

int	destroy_mutex(t_table *table, int idx)
{
	pthread_mutex_t	mutex;

	while (idx--)
	{
		mutex = table->mutex_forks[idx];
		pthread_mutex_destroy(&mutex);
	}
	return (1);
}

void	set_fork(t_philosopher *philo)
{
	int	number_of_philos;

	number_of_philos = (philo->data).number_of_philos;
	philo->left_fork = philo->number - 1;
	philo->right_fork = philo->number - 2;
	if (philo->number == 1)
		philo->right_fork = number_of_philos - 1;
	if (philo->number == number_of_philos)
		philo->left_fork = number_of_philos - 1;
}
