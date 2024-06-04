/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:15 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/05 02:25:44 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	(void) game;
	if (keycode == W_KEY)
		move_up(game);
	else if (keycode == S_KEY)
		move_down(game);
	else if (keycode == D_KEY)
		move_right(game);
	else if (keycode == A_KEY)
		move_left(game);
	else if (keycode == ESC_KEY)
		destroy_game_post(game);
	return (0);
}

void	game_initializer(t_game *game)
{
	game->win.x = map_width(game->map[0]);
	game->win.y = map_height(game->map);
	if (game->win.x == 0 || game->win.y == 0)
	{
		free_map(game->map);
		exit(EXIT_FAILURE);
	}
	game->player_checker = 0;
	game->exit_checker = 0;
	game->collectable_counter = 0;
	game->dfs_collectable_counter = 0;
	game->player.collectable_counter = 0;
	game->player.moves_counter = 0;
	game->player.direction = 0;
	game->winning_check = 0;
	player_find(game);
}

void	window_initializer(t_game *game)
{
	game->win.mlx_win = mlx_new_window(game->mlx,
			game->win.x * DIM, game->win.y * DIM, "sbakhit's So_Long");
	load_images(game);
	imgmsg_loadcheck(game);
}

void	valid_path_checker(t_game game)
{
	char	**marked_map;

	marked_map = NULL;
	marked_map = dfs_marker(game.map);
	dfs(&game, marked_map, game.player.position_x / DIM,
		game.player.position_y / DIM);
	if (valid_path_check(game, marked_map) == 0)
	{
		ft_printf("There's No Valid Path.\n");
		free_map(game.map);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2)
		error_print_msg_pre_map(1);
	if (!file_parser(av[1]))
		error_print_msg_pre_map(2);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_print_msg_pre_map(3);
	game.map = map_parser(fd);
	if (!game.map)
		exit(EXIT_FAILURE);
	game_initializer(&game);
	if (!checker(&game))
	{
		error_print_msg(2);
		free_map(game.map);
		exit(EXIT_FAILURE);
	}
	valid_path_checker(game);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(EXIT_FAILURE);
	window_initializer(&game);
	mlx_hook(game.win.mlx_win, 17, 0L, destroy_game_post, &game);
	ft_draw_map(game);
	ft_draw_tiles(game, game.player.direction);
	mlx_key_hook(game.win.mlx_win, key_hook, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (close(fd), 0);
}
