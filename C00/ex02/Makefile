CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp \
	   tests.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = job

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re