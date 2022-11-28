# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:32:26 by yeepark           #+#    #+#              #
#    Updated: 2022/11/28 21:29:50 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
#CFLAGS =  -fsanitize=address
SRC = main.c data.c set_execute.c execute.c utils.c pipe.c
SRCS = $(addprefix srcs/,$(SRC))
MANDATORY_OBJS = $(SRCS:.c=.o)
BONUS_SRC = main_bonus.c data_bonus.c set_execute_bonus.c execute_bonus.c \
			utils_bonus.c pipe_bonus.c
BONUS_SRCS = $(addprefix bonus/,$(BONUS_SRC))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCLUDES = includes
SUBDIR = libft
LIBFT = libft.a
NAME = pipex
ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MANDATORY_OBJS)
endif

all : $(NAME)

bonus :
	@make BONUS=1

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
	make -C $(SUBDIR) all
	cp $(SUBDIR)/$(LIBFT) .

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

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus 
