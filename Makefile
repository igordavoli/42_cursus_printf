# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 20:47:53 by vaferrei          #+#    #+#              #
#    Updated: 2021/10/16 20:45:45 by idavoli-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 	= ./libft/libft.a

NAME	= libftprintf.a

SRCS = ft_printf.c \
	ft_printf_utils.c \
	ft_resolve_dec.c \
	ft_resolve_str.c \
	ft_resolve_ptr.c \
	ft_resolve_chr.c \
	ft_resolve_prc.c \
	ft_resolve_hex.c \
	ft_resolve_uns.c \
	ft_resolve_flg.c


OBJS	= ${SRCS:.c=.o}


CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		$(MAKE) clean -C ./libft
		rm -f ${OBJS}
		rm -f ${BOBJS}

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f ${NAME}

re: fclean all

bonus: all

test: all
	${CC} main.c libftprintf.a libft/libft.a -o teste
	./teste

.PHONY: all, bonus, clean, fclean, re
