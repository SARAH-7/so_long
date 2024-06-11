/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:58:18 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/11 10:00:08 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	int		res;

	res = 0;
	if (keycode == W_KEY)
		res = move_up(game);
	else if (keycode == A_KEY)
		res = move_left(game);
	else if (keycode == S_KEY)
		res = move_down(game);
	else if (keycode == D_KEY)
		res = move_right(game);
	else if (keycode == ESC_KEY)
		bonus_destroy_game_post(game);
	if (res == 1)
	{
		ft_printf("You Youched an Enemy, You Died!\n");
		bonus_destroy_game_post(game);
	}
	return (0);
}

void	game_initializer(t_game *game)
{
	game->win.x = map_width(game->map[0]);
	game->win.y = map_height(game->map);
	if (game->win.x == 0 || game->win.y == 0 || (game->win.x == game->win.y))
	{
		if (game->win.x == game->win.y)
			error_print_msg(8, game->map);
		bonus_free_map(game->map);
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
	game->enemy_checker = 0;
	game->enemy_direction = 0;
	game->speed = 0;
	bonus_player_find(game);
}

void	window_initializer(t_game *game)
{
	game->win.mlx_win = mlx_new_window(game->mlx,
			game->win.x * DIM, game->win.y * DIM, "sbakhit's So_Long");
	bonus_load_images(game);
	bonus_imgmsg_loadcheck(game);
}

void	valid_path_checker(t_game game)
{
	char	**marked_map;

	marked_map = dfs_marker(game.map);
	if (!marked_map)
		error_print_msg(6, game.map);
	dfs(&game, marked_map, game.player.position_x / DIM,
		game.player.position_y / DIM);
	// int	i = 0;
	// while (marked_map[i])
	// 	ft_printf("%s\n", marked_map[i++]);
	if (valid_path_check(game, marked_map) == 0)
		error_print_msg(7, game.map);
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
	game.map = map_parser(fd, av);
	game_initializer(&game);
	bonus_checker(&game);
	valid_path_checker(game);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit(EXIT_FAILURE);
	window_initializer(&game);
	mlx_hook(game.win.mlx_win, 17, 0L, bonus_destroy_game_post, &game);
	bonus_ft_draw_map(game);
	bonus_ft_draw_tiles(game, game.player.direction);
	mlx_key_hook(game.win.mlx_win, key_hook, &game);
	mlx_loop_hook(game.mlx, move_animation, &game);
	mlx_loop(game.mlx);
	bonus_free_map(game.map);
	return (close(fd), 0);
}
