# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 20:08:17 by yeepark           #+#    #+#              #
#    Updated: 2022/12/20 15:41:13 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread 
#CFLAGS = -fsanitize=address -g
LDFLAGS = -lpthread
SRC = main.c data.c data_utils.c init.c utils.c \
	  run.c
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDES)
clean :
	rm -f $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re
