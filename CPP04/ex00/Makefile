NAME := animal

CC := c++

FLAGS := -Wall -Wextra -Werror

HEADERS := Animal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp

SOURCES := main.cpp Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp

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