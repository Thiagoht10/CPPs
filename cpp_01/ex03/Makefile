CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = unnecessaryViolence

REMOVE = rm -rf

SRC = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re