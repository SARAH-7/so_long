/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:59:21 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/11 02:19:44 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_images(t_game *game)
{
	game->album[0].img = mlx_xpm_file_to_image(game->mlx,
			"enemy_imgs/creeper_left.xpm", &game->album[0].img_width,
			&game->album[0].img_height);
	game->album[1].img = mlx_xpm_file_to_image(game->mlx,
			"enemy_imgs/creeper_right.xpm", &game->album[1].img_width,
			&game->album[1].img_height);
}

void	enemy_pos(t_game *game, int i, int j)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (game->map[i][j - k] == '1' || game->map[i][j - k] == 'C')
		{
			ft_printf("Enemy within 3 spaces of wall or coin\n");
			bonus_destroy_game_pre(game);
		}
		k++;
	}
}

void	find_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				game->enemy_checker++;
			j++;
		}
		i++;
	}
	load_enemy_images(game);
}

void	bonus_checker(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player_checker++;
			else if (game->map[i][j] == 'C')
				game->collectable_counter++;
			else if (game->map[i][j] == 'E')
				game->exit_checker++;
			else if (!(game->map[i][j] == '1' || game->map[i][j] == '0'))
				error_print_msg(4, game->map);
			j++;
		}
		i++;
	}
	if (!(game->player_checker == 1 && game->collectable_counter >= 1
			&& game->exit_checker == 1))
		error_print_msg(4, game->map);
	find_enemy(game);
}
