CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -Iinclude

NAME    = coldy

SRCS    = src/main.c \
          src/input/input.c \
		  src/parser/parser.c \
		  src/parser/SplitString.c \
		  src/Commands/builtIns/echo.c \
		  src/Commands/builtIns/exit.c \
		  src/Commands/builtIns/clear.c \
		  src/Commands/builtIns/fileIO/list.c \
		  src/Commands/command.c \
		  src/utils/getuserdata/gethost.c \
		  src/utils/getuserdata/getuser.c \
		  src/utils/getuserdata/getuserpath.c \
		  src/utils/getuserdata/getprompt.c \
		  src/coldy.c

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
