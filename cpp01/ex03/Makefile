# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources and objects
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

# Output
NAME = weapon_game

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all (objects + binary)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Prevent make from confusing these as files
.PHONY: all clean fclean re
