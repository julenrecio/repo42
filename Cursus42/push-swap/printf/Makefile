NAME=libftprintf.a
CC=cc
CFLAGS=-c -Wall -Wextra -Werror
SOURCE=ft_printf.c ft_printf_number.c ft_printf_hex.c ft_printf_pointer.c ft_printf_float.c
OBJ = $(SOURCE:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all