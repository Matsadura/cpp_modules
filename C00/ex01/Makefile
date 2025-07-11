CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = phonebook.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re