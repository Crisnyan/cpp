SRC = Dog.cpp Cat.cpp WrongCat.cpp Brain.cpp Animal.cpp WrongAnimal.cpp main.cpp
OBJ	= $(SRC:%.cpp=%.o)
INCLUDE = Dog.hpp Cat.hpp WrongCat.hpp Brain.hpp Animal.hpp WrongAnimal.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=leak
NAME = I_don\'t_want_to_set_the_world_on_fire

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
