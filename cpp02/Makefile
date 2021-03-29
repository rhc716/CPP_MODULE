ex00 = 00
ex01 = 01
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror

SRCS1 := $(wildcard ./ex00/*.cpp)
SRCS2 := $(wildcard ./ex01/*.cpp)
OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)

all: $(ex00) $(ex01)

.cpp.o: 
	$(CPP) $(CPPFLAGS) -c $^ -o $@

$(ex00): $(OBJS1)
		$(CPP) $(CPPFLAGS) -o $@ $^
$(ex01): $(OBJS2)
		$(CPP) $(CPPFLAGS) -o $@ $^

clean: 
	rm -f ./ex00/*.o
	rm -f ./ex01/*.o

fclean: clean
	rm -f $(ex00)
	rm -f $(ex01)

re: fclean all

.PHONY: all clean fclean re