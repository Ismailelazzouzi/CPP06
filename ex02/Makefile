NAME = Base
CPP = c++ -Wall -Wextra -Werror
RM = rm -f
FILES = Base \
		main \

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

%.o: %.cpp Base.hpp
	$(CPP) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean