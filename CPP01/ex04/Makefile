NAME := sed

CC := c++

FLAGS := -Wall -Wextra -Werror

SOURCES := main.cpp Sed.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re