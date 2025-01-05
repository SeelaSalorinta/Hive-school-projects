NAME = push_swap

SRCS = push_swap.c \
       free.c \
       validate_stack.c \
       sort.c \
       count_cost.c \
       count_rotations.c \
       rotate_stacks.c \
       find_index.c \
       from_b_to_a.c \
       swap.c \
       push.c \
       rotate.c \
       reverse_rotate.c \
       ft_atoi2.c \
       print_error.c

OBJS = $(SRCS:.c=.o)

LIBFTDIR = libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = $(LIBFTDIR)/libft.a

INCLUDES = -I. -I $(LIBFTDIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
