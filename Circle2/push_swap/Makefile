# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:16:31 by yeepark           #+#    #+#              #
#    Updated: 2022/11/11 22:10:03 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c numbers.c check.c error.c \
	  node.c stack.c init_stack.c rank.c \
	  swap.c push.c rotate.c print.c \
	  sort.c sort_smallsize.c find.c  
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
BONUS_SRC = main.c numbers.c check.c error.c \
	  node.c stack.c init_stack.c rank.c \
	  utils.c operation.c operation2.c\
	  sort.c sort_smallsize.c find.c  
BONUS_SRCS = $(addprefix bonus/,$(SRCS))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCLUDES = includes
SUBDIR = libft
LIBFT = libft.a
BONUS = checker
NAME = push_swap

all : $(NAME)

#bonus :

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
