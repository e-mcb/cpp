NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
STD_FLAGS = -std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

std: CXXFLAGS += $(STD_FLAGS)
std: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re std
