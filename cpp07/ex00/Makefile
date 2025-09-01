SRC = main.cpp
OBJ	= $(SRC:%.cpp=%.o)
INCLUDE = whatever.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=leak
NAME = Start_with_a_few_functions

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
