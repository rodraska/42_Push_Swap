# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:18:03 by rreis-de          #+#    #+#              #
#    Updated: 2023/01/30 16:02:01 by rreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = algo.c \
		lists.c \
		moves.c \
		push_swap.c \
		printf/ft_letters.c \
		printf/ft_numbers.c \
		printf/ft_printf.c \
		printf/ft_putchar_fd.c \
		printf/ft_putstr_fd.c \
		printf/ft_itoa.c \
		printf/ft_strlen.c \
		printf/ft_putnbr_fd.c \
		

HEADERS = push_swap.h 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

		