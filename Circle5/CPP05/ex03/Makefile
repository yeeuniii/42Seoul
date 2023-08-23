CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  
NAME = intern
SRCS = \
	main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp
OBJS = $(SRCS:.cpp=.o)
TREES = $(wildcard ./*_shrubbery) 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CXXFLAGS) -c -o $@ $^

clean :
	rm -f $(OBJS)
	rm -f $(TREES)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

