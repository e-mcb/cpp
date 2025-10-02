# Compiler and flags
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror

# Source files and object files
SRCS    := main.cpp PhoneBook.cpp Contact.cpp
OBJS    := $(SRCS:.cpp=.o)

# Executable name
NAME    := phonebook

# Default target
all: $(NAME)

# Link object files to create the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything (object files + executable)
fclean: clean
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

.PHONY: all clean fclean re
