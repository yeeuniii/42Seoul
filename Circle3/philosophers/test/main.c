#include "includes/philosophers.h"

int number_of_philos = 5;

void	*run(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	philo->table->is_end = philo->number;
//	printf("in number : %d is_end : %d\n", philo->number, philo->table.is_end);
	return (0);
}

void	test(t_table *table)
{
	int				idx = 0;
	t_philosopher	*philo;

	table->philos = malloc(sizeof(t_philosopher) * number_of_philos);
	while (idx < number_of_philos)
	{
		philo = table->philos + idx;
		philo->table = table;
		philo->number = idx + 1;
//		printf("table : %p\n", table);
//		printf("before run\nnumber : %d is_end : %p\n", philo->number, &philo->table);
		pthread_create(&philo->thread, 0, run, (void *)philo);
		idx ++;
	}
	table->is_end = 100;
	while (idx --)
	{
		philo = table->philos + idx;
		pthread_join(philo->thread, 0);
		printf("number : %d is_end : %d\n", philo->number, philo->table->is_end);
	}
	printf("table->is_end : %d\n", table->is_end);
}

int	main(void)
{
	t_table table;

	table.is_end = 0;
	test(&table);
}
