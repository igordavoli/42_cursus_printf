# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 15:35:57 by idavoli-          #+#    #+#              #
#    Updated: 2021/10/13 01:45:13 by idavoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT=./libft/libft.a

NAME=libftprintf.a

SRCS= ft_printf.c \
	ft_printf_utils.c \
	ft_resolve_dec.c \
	ft_resolve_str.c \
	ft_resolve_ptr.c \
	ft_resolve_chr.c \
	ft_resolve_prc.c \
	ft_resolve_hex.c \
	ft_resolve_uns.c

OBJS=${SRCS:.c=.o}

CC=clang

CFLAGS=-Wall -Wextra -Werror -g

${NAME}: ${OBJS}
	@cp $(LIBFT) $(NAME)
	@ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME} *.o

re: fclean all

bonus: all

tests_run: all
	@${CC} main.c $(NAME) $(LIBFT) -o teste.o
	@./teste.o
	@make fclean

.PHONY: all, bonus, clean, fclean, re
