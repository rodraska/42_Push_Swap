# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreis-de <rreis-de@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:18:03 by rreis-de          #+#    #+#              #
#    Updated: 2023/02/04 17:50:57 by rreis-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -f

SRCS = algo.c \
		algo2.c \
		lists.c \
		lists2.c \
		lists3.c \
		moves.c \
		push_swap.c \
		others.c \
		printf/ft_letters.c \
		printf/ft_numbers.c \
		printf/ft_printf.c \
		printf/ft_putchar_fd.c \
		printf/ft_putstr_fd.c \
		printf/ft_itoa.c \
		printf/ft_strlen.c \
		printf/ft_putnbr_fd.c
	
CHECKER_SRCS = lists.c \
				lists2.c \
				lists3.c \
				checker_main.c \
				checker_read.c \
				checker_moves.c \
				printf/ft_letters.c \
				printf/ft_numbers.c \
				printf/ft_printf.c \
				printf/ft_putchar_fd.c \
				printf/ft_putstr_fd.c \
				printf/ft_itoa.c \
				printf/ft_strlen.c \
				printf/ft_putnbr_fd.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c
				

OBJS = $(SRCS:.c=.o)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER_NAME)

clean:
	$(RM) $(OBJS)

clean_checker:
	$(RM) $(CHECKER_OBJS)

fclean: clean
	$(RM) $(NAME)

fclean_checker: clean
	$(RM) $(CHECKER_NAME)

re: fclean $(NAME)

re_checker: fclean_checker $(CHECKER_NAME)

.PHONY: all clean fclean re