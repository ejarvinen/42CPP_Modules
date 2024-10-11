NAME := fixed

CC := c++

FLAGS := -Wall -Wextra -Werror

SOURCES := main.cpp Fixed.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re