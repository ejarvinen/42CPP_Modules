NAME := horde

CC := g++

FLAGS := -Wall -Wextra -Werror

SOURCES := main.cpp Zombie.cpp zombieHorde.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re