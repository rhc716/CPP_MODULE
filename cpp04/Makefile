ex00 = 00
ex01 = 01
ex02 = 02
ex03 = 03
CPP = clang++
CPPFLAGS = -Wall -Wextra -Werror

SRCS1 := $(wildcard ./ex00/*.cpp)
SRCS2 := $(wildcard ./ex01/*.cpp)
SRCS3 := $(wildcard ./ex02/*.cpp)
SRCS4 := $(wildcard ./ex03/*.cpp)
OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)
OBJS3 = $(SRCS3:.cpp=.o)
OBJS4 = $(SRCS4:.cpp=.o)

all: $(ex00) $(ex01) #$(ex02) $(ex03) 

.cpp.o: 
	$(CPP) $(CPPFLAGS) -c $^ -o $@

$(ex00): $(OBJS1)
		$(CPP) $(CPPFLAGS) -o $@ $^
$(ex01): $(OBJS2)
		$(CPP) $(CPPFLAGS) -o $@ $^
$(ex02): $(OBJS3)
		$(CPP) $(CPPFLAGS) -o $@ $^
$(ex03): $(OBJS4)
		$(CPP) $(CPPFLAGS) -o $@ $^
clean: 
	rm -f ./ex00/*.o
	rm -f ./ex01/*.o
	rm -f ./ex02/*.o
	rm -f ./ex03/*.o

fclean: clean
	rm -f $(ex00)
	rm -f $(ex01)
	rm -f $(ex02)
	rm -f $(ex03)

re: fclean all

.PHONY: all clean fclean re