UNAME := $(shell uname)

NAME=bureaucrat
SRC=	Bureaucrat.cpp \
		Form.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		main.cpp
OBJ=${.cpp=.o}

ifeq ($(UNAME), Darwin) # MAC
	FLAG= -Wall -Werror -Wextra
	KEY= 1
endif
ifeq ($(UNAME), Linux) # LINUX
	FLAG= -Wall -Werror -Wextra
	KEY= 2
endif

all: $(NAME)

$(NAME):	$(SRC)
	@clang++ $(FLAG) -o $(NAME) -g $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
