# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:32:26 by yeepark           #+#    #+#              #
#    Updated: 2022/11/28 19:32:50 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
#CFLAGS =  -fsanitize=address
SRC = main.c data.c set_execute.c execute.c utils.c pipe.c
SRCS = $(addprefix srcs/,$(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = includes
SUBDIR = libft
LIBFT = libft.a
NAME = pipex

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

re : 
	make fclean
	make all

.PHONY : all clean fclean re
