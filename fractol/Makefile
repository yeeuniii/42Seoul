# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 11:49:10 by yeepark           #+#    #+#              #
#    Updated: 2022/10/26 22:24:03 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
SRC = main.c utils.c init.c image.c set.c hook.c color.c
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDE = includes
SUBDIR = libft
LIBFT = libft.a
NAME = fractol

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDE)

clean	:
	make -C $(SUBDIR) clean
	rm -f $(OBJS)
	rm -f $(LIBFT)

fclean	: clean
	make -C $(SUBDIR) fclean
	rm -f $(NAME)

re		: fclean 
	make all

.PHONY : all clean fclean re
