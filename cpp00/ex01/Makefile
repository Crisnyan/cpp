SRC = Phonebook.cpp
OBJ	= $(SRC:%.cpp=%.o)
CC = c++
CFLAGS = -Wall -Werror -Wextra -fsanitize=leak
NAME = Phonebook

all: $(NAME)
	
$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

good: all clean

.PHONY: all clean fclean re good
