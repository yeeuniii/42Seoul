#include "../includes/push_swap.h"

int    change_str_to_int(t_numbers **numbers, char **numbers_str)
{
    int idx;
    int size;

    idx = 0;
    size = (*numbers)->size;
    (*numbers)->numbers = malloc(sizeof(int) * size);
    if ((*numbers)->numbers)
        return (0);
    while (idx < size && ft_isinteger(numbers_str[idx]))
    {
        ((*numbers)->numbers)[idx] = ft_atoi(numbers_str[idx]);
        idx ++;
    }
    return (idx == size);
}

t_numbers   *get_numbers(int argc, char *argv[])
{
	t_numbers   *numbers;
    char        **numbers_str;

    numbers = malloc(sizeof(t_numbers));
    if (!numbers)
        return (0);
    if (argc > 2)
	{
		numbers->size = argc - 1;
		numbers_str = argv + 1;
	}
    if (argc == 2)
    	numbers_str = ft_split(argv[1], ' ', &(numbers->size));
    change_str_to_int(&numbers, numbers_str);
    check_duplicated(numbers);
//	if (!numbers)
//		*limit = -1;
	return (numbers);
}

void	free_numbers(int argc, char **numbers)
{
	int	idx;

	if (argc != 2)
		return ;
	idx = 0;
	while (numbers[idx])
	{
		free(numbers[idx]);
		idx ++;
	}
	free(numbers);
}