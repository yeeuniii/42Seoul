CFLAGS = -Wall -Wextra -Werror
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
SRC = main.c
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
DIRMLX = mlx
LIBMLX = mlx/libmlx.a
NAME = minirt


all : $(NAME)


$(NAME) : $(LIBMLX) $(OBJS)
	$(CC) $^ -o $@ $(CLIB) $(CFLAGS)


$(LIBMLX) : 
	make -C $(DIRMLX) all


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : all clean fclean re
