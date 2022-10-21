# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 11:49:10 by yeepark           #+#    #+#              #
#    Updated: 2022/10/20 22:03:00 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CFLAGS = -Wall -Wextra -Werror
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
SRCS = main.c utils.c init.c image.c set.c hook.c libft/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
NAME = fractol 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean 
	make all

.PHONY : all clean fclean re
