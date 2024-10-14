NAME := violence

CC := c++

FLAGS := -Wall -Wextra -Werror

SOURCES := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re