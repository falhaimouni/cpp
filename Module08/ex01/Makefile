CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME =  span
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:%.cpp=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

objs/%.o: %.cpp
	@mkdir -p objs
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
