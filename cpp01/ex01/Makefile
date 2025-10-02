# Makefile

# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp Zombie.cpp zombieHorde.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = zombie

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
