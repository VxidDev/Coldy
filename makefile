CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -Iinclude

NAME    = coldy

SRCS    = src/main.c \
          src/input/input.c \
		  src/parser/parser.c \
		  src/parser/SplitString.c \
		  src/Commands/builtIns/echo.c \
		  src/Commands/builtIns/exit.c \
		  src/Commands/command.c 

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
