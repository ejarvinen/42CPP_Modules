NAME := violence

CC := c++

FLAGS := -Wall -Wextra -Werror

HEADERS := HumanA.hpp HumanB.hpp Weapon.hpp

SOURCES := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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