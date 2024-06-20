# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rohta <rohta@student.42.jp>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 16:13:24 by rohta             #+#    #+#              #
#    Updated: 2024/06/20 16:47:47 by rohta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CDLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_check.c ft_params_init.c ft_apply_csp.c \
			ft_apply_diuxX.c ft_write_string.c ft_write_number.c \
			ft_write_hexdecimal.c

OBJ = $(SRC:.c=.o)

LIBFT_OBJ = ./libft/libft.a

all: $(NAME)

bonus: all

$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C ./libft

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME) ./libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
