NAME := harl

CC := g++

FLAGS := -std=c++11 -Wall -Wextra -Werror

SOURCES := main.cpp Harl.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re