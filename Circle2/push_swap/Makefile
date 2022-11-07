# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:16:31 by yeepark           #+#    #+#              #
#    Updated: 2022/11/07 16:37:45 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c numbers.c check.c error.c node.c \
	  stack.c init_stack.c utils.c rank.c \
	  operation.c operation2.c test.c 
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
SUBDIR = printf
PRINTF = libftprintf.a
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(PRINTF) .
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDES)

clean : 
	make -C $(SUBDIR) clean
	rm -f $(OBJS)
	rm -f $(PRINTF)

fclean : clean
	make -C $(SUBDIR) fclean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
