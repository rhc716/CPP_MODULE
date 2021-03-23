NAME = megaphone
CC = clang++
CFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re