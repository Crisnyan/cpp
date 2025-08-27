SRC = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp
OBJ	= $(SRC:%.cpp=%.o)
INCLUDE = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp 
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=leak
NAME = At_least_this_beats_coffee-making

all: $(NAME)
	
$(NAME): $(INCLUDE) $(OBJ) Makefile
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re: fclean all

good: all clean

.PHONY: all clean fclean re good
