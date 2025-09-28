# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 20:12:45 by takenakatak       #+#    #+#              #
#    Updated: 2025/09/29 02:20:01 by takenakatak      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes -I libft

SRC = ./src/ft_printf.c ./src/print_c.c ./src/print_di.c ./src/print_p.c\
	./src/print_s.c ./src/print_u.c ./src/print_x.c ./src/utils.c

OBJ = $(SRC:%.c=%.o)

.PHONY:all
all:$(NAME)

$(NAME):$(OBJ)
	make -C ./libft
	cp ./libft/libft.a $@
	ar csr $@ $?

./src/%.o: ./src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	make -C ./libft clean
	rm -f $(OBJ)

.PHONY:fclean
fclean:clean
	make -C ./libft fclean
	rm -f $(NAME)

.PHONY:re
re:fclean all