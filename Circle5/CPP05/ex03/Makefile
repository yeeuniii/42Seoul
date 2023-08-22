CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
NAME = form
SRCS = \
	main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp
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

