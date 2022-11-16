# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:16:31 by yeepark           #+#    #+#              #
#    Updated: 2022/11/16 15:39:53 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c numbers.c check.c error.c \
	  node.c stack.c init_stack.c rank.c \
	  swap.c push.c rotate.c print.c \
	  sort.c sort_smallsize.c sort_utils.c  
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
BONUS_SRC = main.c numbers.c check.c error.c \
			node.c stack.c init_stack.c  \
			swap.c push.c rotate.c print.c operation_both.c \
			sort.c sort_utils.c get_next_line.c get_next_line_utils.c
BONUS_SRCS = $(addprefix bonus/,$(BONUS_SRC))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCLUDES = includes
SUBDIR = libft
LIBFT = libft.a
BONUS = checker
NAME = push_swap

all : $(NAME)

bonus : $(BONUS)

both :
	make all
	make bonus

$(NAME) : $(OBJS)
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(BONUS) : $(BONUS_OBJS) 	
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(BONUS_SRCS) $(LIBFT) -o $(BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDES)

clean : 
	make -C $(SUBDIR) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(LIBFT)

fclean : clean
	make -C $(SUBDIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS)

re : fclean
	make all

.PHONY : all bonus both clean fclean re
