# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:58:12 by sbakhit           #+#    #+#              #
#    Updated: 2024/07/02 19:19:47 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Names
NAME = so_long
BONUS_NAME = so_long_bonus

# Libraries
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

# Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L $(MINILIBX_PATH) -lmlx -Imlx -framework OpenGL -framework AppKit

# Source Files
CFILES = so_long.c file_parser.c map_parser.c get_next_line.c get_next_line_utils.c \
map_checker.c freeing_functions.c dfs_marker.c valid_path.c imgs_funcs.c map_draw.c \
moves_updater.c player_moves.c error_print_msg.c map_entries.c shared_func.c

BONUS_DIR = bonus
B_CFILES = $(addprefix $(BONUS_DIR)/,bonus_main.c bonus_checker.c bonus_img_func.c \
bonus_map_draw.c bonus_moves_updater.c bonus_enemy_funcs.c bonus_enemy_kill_func.c \
bonus_freeing_funcs.c bonus_player_moves.c bonus_valid_path.c bonus_shared_func.c \
bonus_map_parser.c bonus_map_entries.c bonus_file_parser.c bonus_dfs_marker.c \
find_enemy.c bonus_common.c) error_print_msg.c get_next_line.c get_next_line_utils.c

# Targets
all: $(NAME)

$(NAME): $(CFILES)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(MAKE) -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(CFILES) $(LIBFT) $(FT_PRINTF) $(MLXFLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_CFILES)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(MAKE) -C $(MINILIBX_PATH)
	$(CC) $(CFLAGS) $(B_CFILES) $(LIBFT) $(FT_PRINTF) $(MLXFLAGS) -o $(BONUS_NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	make clean -C $(MINILIBX_PATH)
	rm -f *.o $(BONUS_DIR)/*.o

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
