# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:16:31 by yeepark           #+#    #+#              #
#    Updated: 2022/11/04 16:56:06 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c init.c check.c error.c node.c \
	  stack.c utils.c  test.c 
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
