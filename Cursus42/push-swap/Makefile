# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: jrecio-t <jrecio-t@student.42urduliz.com>    +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/06/08 09:31:55 by azahino-            #+#    #+#             #
#   Updated: 2026/07/01 10:14:06 by jrecio-t           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRC = src/main.c src/disorder.c src/utils_main.c src/utils_alg.c src/utils_list.c \
src/utils_str.c alg/alg_medium.c alg/alg_simple.c alg/alg_complex.c alg/alg_adaptive.c \
src/push.c src/swap.c src/rotate.c src/reverse.c src/bench.c src/repetition.c src/split.c \
src/errors.c src/mode.c

BONUS_SRC = bonus/checker_main.c bonus/checker_utils.c gnl/get_next_line.c gnl/get_next_line_utils.c \
src/utils_main.c src/utils_list.c src/utils_str.c src/push.c src/swap.c src/rotate.c \
src/reverse.c src/split.c src/errors.c src/repetition.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

PRINTF_PATH = printf/libftprintf.a

.PHONY: all clean fclean re bonus

all: $(NAME)
	
$(PRINTF_PATH):
	make -C printf

$(NAME): $(OBJ) $(PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_PATH) -o $(NAME)
	
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(PRINTF_PATH)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(PRINTF_PATH) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C printf clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C printf fclean

re: fclean all