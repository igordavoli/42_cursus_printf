# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 20:47:53 by vaferrei          #+#    #+#              #
#    Updated: 2021/11/02 02:10:15 by idavoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_printf_puts.c \
	ft_resolve_dec.c \
	ft_resolve_str.c \
	ft_resolve_ptr.c \
	ft_resolve_chr.c \
	ft_resolve_hex.c \
	ft_resolve_uns.c \
	ft_resolve_flg.c \
	ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

CC = clang

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	@make  -C ./libft
	@cp libft/libft.a $(NAME)
	@ar -rcs ${NAME} ${OBJS}

all: ${NAME}

re: fclean all

bonus: all

test: all
	@${CC} -g main.c libftprintf.a libft/libft.a
	@make clean

test_run : test
	@./a.out
	@make fclean

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}
	@rm -f ${BOBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}
	@rm a.out

.PHONY: all, bonus, clean, fclean, re
