NAME := megaphone

CC := c++

FLAGS := -Wall -Wextra -Werror

SOURCES := megaphone.cpp

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re