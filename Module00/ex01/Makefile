CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = phonebook
SRCS = main.cpp \
	   PhoneBook.cpp \
	   Contact.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
