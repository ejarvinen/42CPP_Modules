NAME := fragtrap

CC := c++

FLAGS := -Wall -Wextra -Werror

HEADERS := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

SOURCES := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJECTS := $(SOURCES:.cpp=.o)

all: $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJECTS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY = all fclean re clean