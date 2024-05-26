/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:15 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/26 17:30:01 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_find(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player.position_x = j * DIM;
				game->player.position_y = i * DIM;
			}
			j++;
		}
		i++;
	}
}

void	initializer(t_game *game)
{
	int	x;
	int	y;

	x = map_width(game->map[0]);
	y = map_height(game->map);
	game->player_checker = 0;
	game->exit_checker = 0;
	game->collectable_checker = 0;
	game->dfs_collectable_counter = 0;
	game->player.collectable_checker = 0;
	game->player.moves_counter = 0;
	game->player.direction = 0;
	game->winning_check = 0;
	game->win.x = x;
	game->win.y = y;
	game->win.mlx_win = mlx_new_window(game->mlx,
			game->win.x * DIM, game->win.y * DIM, "sbakhit's So_Long");
	player_find(game);
}

int	map_parsing_check(char **marked_map, t_game game)
{
	marked_map = dfs_marker(game.map);
	dfs(&game, marked_map, game.player.position_x / DIM,
		game.player.position_y / DIM);
	if (valid_path_check(game, marked_map) == 0)
		return (ft_printf("There's No Valid Path\n", 0));
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;
	char	**marked_map;

	if (ac != 2)
		return (ft_printf("Enter Only Two Arguments\n"), 1);
	marked_map = NULL;
	fd = open(av[1], O_RDONLY);
	if (!file_parser(av[1]) || fd == -1)
	{
		if (!file_parser(av[1]))
			close(fd);
		return (ft_printf("Enter a Valid File\n"), 1);
	}
	game.map = map_parser(fd);
	game.mlx = mlx_init();
	if (!game.map || !game.mlx)
		return (1);
	initializer(&game);
	int i = 0;
    while (game.map[i])
        i++;
    game.map[i] = NULL;
	elements_checker(&game);
	if (game.map)
	{
		if (!map_parsing_check(marked_map, game))
			return (1);
	}
	mlx_hook(game.win.mlx_win, 17, 0L, destroy_game_post, &game);
	ft_draw_map(game);
	// ft_draw_tiles(game, game.player.dir);
	// i = 0;
	// while (game.map[i] && game.map[i] != NULL)
	// {
	// 	ft_printf("[%s]\n", game.map[i]);
	// 	i++;
	// }
}
