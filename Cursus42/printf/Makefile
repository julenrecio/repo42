NAME=printf.a
CC=cc
CFLAGS=-c -Wall -Wextra -Werror
SOURCE=ft_printf.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all