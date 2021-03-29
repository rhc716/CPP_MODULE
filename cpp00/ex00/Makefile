NAME = megaphone
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o: 
	$(CPP) $(CPPFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) -o $@ $^

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re