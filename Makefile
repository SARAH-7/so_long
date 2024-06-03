# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:58:12 by sbakhit           #+#    #+#              #
#    Updated: 2024/06/03 20:23:09 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
MINILIBX = minilibx/libmlx.a

NAME = $(SO_LONG)
SOURCES = so_long.c file_parser.c map_parser.c get_next_line.c get_next_line_utils.c \
map_checker.c freeing_functions.c dfs_marker.c valid_path.c imgs_funcs.c map_draw.c \
moves_updater.c player_moves.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LDFLAGS = -Llibft -Lft_printf -Lminilibx -lft -lftprintf -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(MINILIBX):
	make -C minilibx

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Ift_printf -Iminilibx -c $< -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	make clean -C minilibx
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
