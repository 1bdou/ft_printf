NAME = libftprintf.a

SOURCES = check_format.c ft_putchar.c ft_putnbr.c ft_putstr.c \
convert_to_hex.c ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS):$(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
	$(AR) -rcs $(NAME) $(OBJECTS)


clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	