# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:29:07 by rreis-de          #+#    #+#              #
#    Updated: 2023/01/30 15:49:42 by rreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRCS = ft_printf.c \
		ft_letters.c \
		ft_numbers.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

HEADERS = ft_printf.h

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -o ${NAME} 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re