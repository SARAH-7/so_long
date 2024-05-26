/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:39:51 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/17 20:56:39 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_images(t_game *game)
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
}

void	destroy_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	destroy_game_pre(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	destroy_map(game->map);
	exit(0);
}

int	destroy_game_post(t_game *game)
{
	if (game->winning_check == 0)
		ft_printf("Game has exited\n");
	else if (game->winning_check == 1)
		ft_printf("Congrats! You have won\n");
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	destroy_map(game->map);
	exit(0);
}