ex00 = 00
CPP = clang++ #-std=c++98
CPPFLAGS = -Wall -Wextra -Werror

SRCS1 = main.cpp
OBJS1 = $(SRCS1:.cpp=.o)

all: $(ex00)

.cpp.o: 
	$(CPP) $(CPPFLAGS) -c $^ -o $@

$(ex00): $(OBJS1)
		$(CPP) $(CPPFLAGS) -o $@ $^
clean: 
	rm -f $(OBJS1)

fclean: clean
	rm -f $(ex00)

re: fclean all

.PHONY: all clean fclean re