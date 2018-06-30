.PHONY: all clean fclean re

NAME = ft_gkrellm

SRCS = main.cpp IMonitorModule.cpp IMonitorDisplay.cpp

HEADERS = IMonitorDisplay.hpp IMonitorModule.hpp

OBJ = $(SRCS:.cpp=.o)

CFLAGS = -std=c++98 -Wall -Werror -Wextra

CC = clang++

all: $(NAME) $(OBJ)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -lncurses $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all