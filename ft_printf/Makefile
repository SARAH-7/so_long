# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 20:14:17 by sbakhit           #+#    #+#              #
#    Updated: 2024/01/13 13:18:15 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned_int.c\
	ft_putnbr_hex.c ft_putpointer.c ft_putnbr_hex_cap.c


OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re