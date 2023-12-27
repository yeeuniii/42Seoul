CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = aanimal 
SRCS = main.cpp \
	AAnimal.cpp \
	Dog.cpp \
	Cat.cpp \
	Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.c
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re