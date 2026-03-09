NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_aux_fun.c ft_complex.c ft_fivenum.c ft_list_tools.c ft_push_swap.c ft_simplen.c ft_stackorder_r.c ft_stackorder_s.c \
ft_adaptive.c ft_benchmark.c ft_disorder_index.c ft_inputs.c ft_medium.c ft_simple.c ft_stackorder_p.c ft_stackorder_rr.c \

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