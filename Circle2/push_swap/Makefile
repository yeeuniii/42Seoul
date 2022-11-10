# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:16:31 by yeepark           #+#    #+#              #
#    Updated: 2022/11/10 19:41:57 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c numbers.c check.c error.c node.c \
	  stack.c init_stack.c utils.c rank.c \
	  operation.c operation2.c sort.c sort_smallsize.c test.c 
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
SUBDIR = libft
LIBFT = libft.a
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDES)

clean : 
	make -C $(SUBDIR) clean
	rm -f $(OBJS)
	rm -f $(LIBFT)

fclean : clean
	make -C $(SUBDIR) fclean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
