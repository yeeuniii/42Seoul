# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:16:31 by yeepark           #+#    #+#              #
#    Updated: 2022/10/28 22:25:35 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRC = main.c
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDE = includes
SUBDIR = printf
PRINTF = libftprintf.a
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(PRINTF) .
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUD)

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
