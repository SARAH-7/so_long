# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:58:12 by sbakhit           #+#    #+#              #
#    Updated: 2024/06/11 07:42:54 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
MINILIBX = minilibx/libmlx.a

SOURCES = so_long.c file_parser.c map_parser.c get_next_line.c get_next_line_utils.c \
map_checker.c freeing_functions.c dfs_marker.c valid_path.c imgs_funcs.c map_draw.c \
moves_updater.c player_moves.c error_print_msg.c map_entries.c shared_func.c

BONUS_DIR = bonus

B_SOURCES = $(addprefix $(BONUS_DIR)/,bonus_main.c bonus_map_checker.c bonus_img_func.c \
bonus_map_draw.c bonus_moves_updater.c bonus_enemy_funcs.c bonus_enemy_kill_func.c \
bonus_freeing_funcs.c bonus_player_moves.c) file_parser.c dfs_marker.c valid_path.c \
error_print_msg.c map_entries.c map_parser.c get_next_line.c get_next_line_utils.c \
shared_func.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJS = $(B_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
LDFLAGS = -Llibft -Lft_printf -Lminilibx -lft -lftprintf -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

$(MINILIBX):
	make -C minilibx

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Ift_printf -Iminilibx -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -Ilibft -Ift_printf -Iminilibx -c $< -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	make clean -C minilibx
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
