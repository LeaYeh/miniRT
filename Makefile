NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -lcriterion -lm
SRC = $(wildcard source/*.c) $(wildcard tests/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
