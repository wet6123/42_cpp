NAME = Zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

HEADER = Zombie.hpp
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp: .o
	$(CXX) $(CXXFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)
	$(MAKE) clean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re