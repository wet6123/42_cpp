NAME = main
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp: .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

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