CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
	   PhoneBook.cpp \
	   Contact.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re