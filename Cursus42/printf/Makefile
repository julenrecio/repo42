NAME=libftprintf.a
CC=cc
CFLAGS=-c -Wall -Wextra -Werror
SOURCE=ft_printf.c ft_printf_number.c
OBJ = $(SOURCE:.c=.o)
LIBFT=./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all