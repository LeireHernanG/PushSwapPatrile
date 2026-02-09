NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = 


OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
    $(AR) $@ $^

%.o: %.c $(INCLUDE) Makefile
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    $(RM) $(OBJ)

fclean: clean
    $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
