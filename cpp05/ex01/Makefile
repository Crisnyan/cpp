SRC = Bureaucrat.cpp Form.cpp main.cpp
OBJ	= $(SRC:%.cpp=%.o)
INCLUDE = Bureaucrat.hpp Form.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=leak
NAME = Form_up,_maggots!

all: $(NAME)
	
$(NAME): $(INCLUDE) $(OBJ) Makefile
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

good: all clean

.PHONY: all clean fclean re good
