NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC =


OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h libft.h

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -Ilibft -c -o $@ $<

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
