NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

HEADER = Account.hpp
SRCS = Account.cpp tests.cpp
OBJS = Account.o tests.o

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