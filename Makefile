# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopp <stopp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:08:04 by stopp             #+#    #+#              #
#    Updated: 2024/01/15 14:15:57 by stopp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

LIBFTPRINTF = ft_printf/libftprintf.a
SRCS = main.c error_check.c init_a.c move_nodes.c pswap_utils.c push.c reverse_rotate.c rotate.c sort.c swap.c \
		update_stackA.c update_stackB.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -g

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(LIBFTPRINTF) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
