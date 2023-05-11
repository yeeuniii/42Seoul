CFLAGS = -Wall -Wextra -Werror
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
SRC = main.c vector_utils.c init.c ray.c
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
DIRMLX = mlx
LIBMLX = mlx/libmlx.a
NAME = minirt

RM = rm -f

all : $(NAME)


$(NAME) : $(LIBMLX) $(OBJS)
	$(CC) $^ -o $@ $(CLIB) $(CFLAGS)


$(LIBMLX) : 
	make -C $(DIRMLX) all


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJS)


fclean : clean
	$(RM) $(NAME)


re : fclean
	make all


.PHONY : all clean fclean re
