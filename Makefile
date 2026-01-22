# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nohubert <nohubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 10:08:34 by nohubert          #+#    #+#              #
#    Updated: 2025/09/25 16:49:46 by nohubert         ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_DIR = src

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I ${LIBFT_DIR} -I ${PRINTF_DIR}/include -g3

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

PRINTF_DIR = ft_printf
PRINTF = ${PRINTF_DIR}/libftprintf.a

SRC = ${SRC_DIR}/main.c ${SRC_DIR}/parsing.c ${SRC_DIR}/path.c\
	  ${SRC_DIR}/utils.c ${SRC_DIR}/cleanup.c ${SRC_DIR}/init.c\
	  ${SRC_DIR}/fd.c ${SRC_DIR}/exec.c

OBJS = ${SRC:.c=.o}

all:	${NAME}

${NAME}:	${LIBFT} ${PRINTF} ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${PRINTF} ${LIBFT}

${PRINTF}:
	${MAKE} -C ${PRINTF_DIR}

${LIBFT}:
		${MAKE} -C ${LIBFT_DIR}

${SRC_DIR}/%.o: ${SRC_DIR}/%.c include/pipex.h
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${MAKE} -C ${LIBFT_DIR} clean
		${MAKE} -C ${PRINTF_DIR} clean
		rm -f ${OBJS}

fclean:	clean
		${MAKE} -C ${LIBFT_DIR} fclean
		${MAKE} -C ${PRINTF_DIR} fclean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
