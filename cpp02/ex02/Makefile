SRC = Fixed.cpp main.cpp
OBJ	= $(SRC:%.cpp=%.o)
INCLUDE = Fixed.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=leak
NAME = "Now_we're_talking"

all: $(NAME)
	
$(NAME): $(OBJ) Makefile
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

good: all clean

.PHONY: all clean fclean re good
