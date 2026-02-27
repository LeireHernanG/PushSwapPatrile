NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_adaptative.c ft_buble_sort.c ft_disorder_index.c ft_list_tools.c \
      ft_medium.c ft_push_swap.c ft_radix.c ft_stackorder_p.c \
      ft_stackorder_r.c ft_stackorder_rr.c ft_stackorder_s.c inputs.c

OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h
LIBFT = libft/libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re