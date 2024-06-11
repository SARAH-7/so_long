/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_freeing_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:36:06 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/11 06:47:14 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	bonus_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !(*map))
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	bonus_destroy_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->album[i].img == NULL)
		{
			i++;
			continue ;
		}
		mlx_destroy_image(game->mlx, game->album[i++].img);
	}
	i = 0;
	while (i < 2)
	{
		if (game->enemy_album[i].img == NULL)
		{
			i++;
			continue ;
		}
		mlx_destroy_image(game->mlx, game->enemy_album[i++].img);
	}
}

void	bonus_destroy_game_pre(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	bonus_free_map(game->map);
}

int	bonus_destroy_game_post(t_game *game)
{
	if (game->winning_check == 0)
		ft_printf("Game Has Exited.\n");
	else if (game->winning_check == 1)
		ft_printf("Congrats! Now Let's Make More Crafts Inside!\n");
	bonus_free_map(game->map);
	bonus_destroy_images(game);
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	exit(0);
}
