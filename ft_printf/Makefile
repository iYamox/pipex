# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 14:30:20 by nohubert          #+#    #+#              #
#    Updated: 2025/06/10 14:54:18 by nohubert         ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src
INCLUDE_DIR = include

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ${INCLUDE_DIR} -I ${LIBFT_DIR}

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

SRC = ${SRC_DIR}/ft_printf.c ${SRC_DIR}/print_char.c \
	  ${SRC_DIR}/print_hex.c ${SRC_DIR}/print_nbr.c \
	  ${SRC_DIR}/print_string.c ${SRC_DIR}/conversions.c

HEADERS = ${LIBFT_DIR}/ft_printf.h

OBJS = ${SRC:.c=.o}

all:	${NAME}

${NAME}:	${LIBFT} ${OBJS}
		cp ${LIBFT} ${NAME}
		ar rcs ${NAME} ${OBJS}

${LIBFT}:
		${MAKE} -C ${LIBFT_DIR}

${SRC_DIR}/%.o: ${SRC_DIR}/%.c
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${MAKE} -C ${LIBFT_DIR} clean
		rm -f ${OBJS}

fclean:	clean
		${MAKE} -C ${LIBFT_DIR} fclean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
