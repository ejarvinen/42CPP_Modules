NAME := PmergeMe

CC := c++

FLAGS := -Wall -Wextra -Werror #-g -fsanitize=address

HEADERS := PmergeMe.hpp

SOURCES := main.cpp\
			PmergeMe.cpp\
			inputValidation.cpp\
			initJacobstahl.cpp\
			vectorVersion/mergeVec.cpp\
			vectorVersion/insertVec.cpp\
			vectorVersion/jacobstahlInsert.cpp\
			vectorVersion/insertVecSingleNums.cpp\
			vectorVersion/vectorVersion.cpp\

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