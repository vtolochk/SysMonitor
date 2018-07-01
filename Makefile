.PHONY: all clean fclean re

NAME = ft_gkrellm

SRCS = main.cpp \
	   UserHost.class.cpp \
	   DateTime.class.cpp \
	   OSInfo.class.cpp \
	   CPU.class.cpp \
	   RAM.class.cpp \
	   TerminalMonitor.class.cpp \

HEADERS = IMonitorDisplay.hpp \
		  IMonitorModule.hpp \
		  UserHost.class.hpp \
		  DateTime.class.hpp \
		  OSInfo.class.hpp \
		  CPU.class.hpp \
		  RAM.class.hpp \
		  TerminalMonitor.class.hpp \

OBJ = $(SRCS:.cpp=.o)

CFLAGS = -g -std=c++98 -Wall -Werror -Wextra

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
