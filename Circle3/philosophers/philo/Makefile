# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 20:08:17 by yeepark           #+#    #+#              #
#    Updated: 2023/01/20 16:08:30 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -fsanitize=address
#CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
LDFLAGS = -lpthread
SRC = main.c utils.c data.c table.c philosopher.c \
	  philo_thread.c state.c monitor_thread.c
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
