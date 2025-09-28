# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 01:54:54 by takenakatak       #+#    #+#              #
#    Updated: 2025/09/29 02:21:16 by takenakatak      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes -I libftprintf/includes

SRC = ./src/args.c ./src/ft_radixsort.c ./src/ft_split.c ./src/lst_func.c\
	./src/mini_push_swap.c ./src/operations_1.c ./src/operations_2.c\
	./src/push_swap.c ./src/utils.c

OBJ = $(SRC:%.c=%.o)

.PHONY:all
all:$(NAME)

$(NAME):$(OBJ)
	make -C ./libftprintf
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libftprintf -lftprintf

./src/%.o: ./src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	make -C ./libftprintf clean
	rm -f $(OBJ)

.PHONY:fclean
fclean:clean
	make -C ./libftprintf fclean
	rm -f $(NAME)

.PHONY:re
re:fclean all