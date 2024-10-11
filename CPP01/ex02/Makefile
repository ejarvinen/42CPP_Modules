NAME := brain

CC := g++

FLAGS := -Wall -Wextra -Werror

SOURCES := main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re