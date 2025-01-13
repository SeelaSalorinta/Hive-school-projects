NAME = pipex

SRCS = pipex.c \
       utils.c \
       utils2.c

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

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
