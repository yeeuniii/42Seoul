#ifndef NUMBERS_H
# define NUMBERS_H

typedef struct s_numbers
{
    int     *numbers;
    int     size;
} t_numbers;

# define INT_MAX 2147483647
# define INT_MIN -2147483648

char    **get_numbers(int argc, char *argv[]);

#endif