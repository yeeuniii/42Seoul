CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN 
SRCS = main.cpp \
	RPN.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CXXFLAGS) -c -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

