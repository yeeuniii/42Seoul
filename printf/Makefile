# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeepark <yeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 14:53:31 by yeepark           #+#    #+#              #
#    Updated: 2022/07/27 16:12:00 by yeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CP = cp
CFLAGS = -Wall -Wextra -Werror
AFLAGS = -rcs
SRCS = ft_printf.c handle.c print.c type.c type2.c 
OBJS = $(SRCS:.c=.o)
SUBDIR = libft
SUBNAME = libft.a
NAME = libftprintf.a
all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(SUBDIR) all
	$(CP) $(SUBDIR)/$(SUBNAME) $(NAME)
	$(AR) $(AFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	$(MAKE) -C $(SUBDIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(SUBDIR) fclean
	$(RM) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
