CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp main.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = zombie

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re