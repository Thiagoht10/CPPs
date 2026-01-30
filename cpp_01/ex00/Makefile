CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = BraiiiiiiinnnzzzZ

SRC = Zombie.cpp randomChump.cpp newZombie.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re