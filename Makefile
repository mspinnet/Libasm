# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 16:08:37 by mspinnet          #+#    #+#              #
#    Updated: 2021/02/17 17:04:46 by mspinnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s

OBJS	= ${SRCS:.s=.o}

NAME	= libasm.a

GCC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

ARRCS	= ar rcs

all:	${NAME}

.s.o:	%.s
		nasm -f macho64 $< -o $@

${NAME}:${OBJS}
		${ARRCS} ${NAME} ${OBJS}

test:	${NAME}
		${GCC} ${CFLAGS} -L. -lasm main.c && ./a.out

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} a.out

re:		fclean all
