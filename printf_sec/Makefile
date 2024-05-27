NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_print_char.c \
	   ft_print_s.c \
	   ft_print_ptr.c \
	   ft_print_nbr.c \
	   ft_print_unsig.c \
	   ft_print_hex.c \

OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
