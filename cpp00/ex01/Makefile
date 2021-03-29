NAME = phonebook
CPP = clang++
CPPFLAG = -Wall -Wextra -Werror

SRCS = main.cpp contact.cpp phonebook.cpp 
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

.cpp.o: 
	$(CPP) $(CPPFLAG) -c $^ -o $@

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAG) -o $@ $^

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re