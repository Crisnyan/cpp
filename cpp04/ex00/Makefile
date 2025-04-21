SRC = Dog.cpp Cat.cpp WrongCat.cpp Animal.cpp WrongAnimal.cpp main.cpp
OBJ	= $(SRC:%.cpp=%.o)
INCLUDE = Cat.hpp WrongCat.hpp Dog.hpp Animal.hpp WrongAnimal.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=leak
NAME = Polymorphism

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
