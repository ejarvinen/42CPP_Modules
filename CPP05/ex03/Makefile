NAME := intern

CC := c++

FLAGS := -Wall -Wextra -Werror

HEADERS := Bureaucrat.hpp\
			AForm.hpp\
			PresidentialPardonForm.hpp\
			RobotomyRequestForm.hpp\
			ShrubberyCreationForm.hpp\
			Intern.hpp

SOURCES := main.cpp\
			Bureaucrat.cpp\
			AForm.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			ShrubberyCreationForm.cpp\
			Intern.cpp

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