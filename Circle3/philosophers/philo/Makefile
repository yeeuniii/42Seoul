# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 20:08:17 by yeepark           #+#    #+#              #
#    Updated: 2022/12/22 21:06:18 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lpthread
SRC = main.c utils.c data.c data_utils.c \
	  init.c init_utils.c philo_thread.c
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
