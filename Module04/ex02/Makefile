CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = Animals
SRCS = main.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp \
		AAnimal.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		

OBJS = $(SRCS:%.cpp=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .cpp into objs/.o
objs/%.o: %.cpp
	@mkdir -p objs
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf objs

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
