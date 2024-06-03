/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:15 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/03 19:24:29 by sbakhit          ###   ########.fr       */
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

void	initializer(t_game *game)
{
	int	x;
	int	y;

	x = map_width(game->map[0]);
	y = map_height(game->map);
	game->player_checker = 0;
	game->exit_checker = 0;
	game->collectable_counter = 0;
	game->dfs_collectable_counter = 0;
	game->player.collectable_counter = 0;
	game->player.moves_counter = 0;
	game->player.direction = 0;
	game->winning_check = 0;
	game->win.x = x;
	game->win.y = y;
	player_find(game);
}

void	map_parsing_check(t_game game)
{
	char	**marked_map;

	marked_map = NULL;
	marked_map = dfs_marker(game.map);
	dfs(&game, marked_map, game.player.position_x / DIM,
		game.player.position_y / DIM);
	if (valid_path_check(game, marked_map) == 0)
	{
		ft_printf("There's No Valid Path.\n");
		destroy_game_pre(&game);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2)
		return (ft_printf("Enter Only Two Arguments.\n"), 1);
	if (!file_parser(av[1]))
		return (ft_printf("Enter a Valid File\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error! Can't Open File.");
		exit(EXIT_FAILURE);
	}
	game.map = map_parser(fd);
	initializer(&game);
	map_parsing_check(game);
	if (game.map && !checker(&game))
	{
		ft_printf("Error! Invalid Map Entries.\n");
		exit(EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	if (!game.map || !game.mlx)
		return (1);
	game.win.mlx_win = mlx_new_window(game.mlx,
			game.win.x * DIM, game.win.y * DIM, "sbakhit's So_Long");
	player_find(&game);
	load_images(&game);
	imgmsg_loadcheck(&game);
	mlx_hook(game.win.mlx_win, 17, 0L, destroy_game_post, &game);
	ft_draw_map(game);
	ft_draw_tiles(game, game.player.direction);
	mlx_key_hook(game.win.mlx_win, key_hook, &game);
	mlx_loop(game.mlx);
	return (close(fd), 0);
}
