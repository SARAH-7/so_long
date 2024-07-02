/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:39:51 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:12:51 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_game_pre(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	free(game->mlx);
	free_map(game->map);
}

int	destroy_game_post(t_game *game)
{
	if (game->winning_check == 0)
		ft_printf("Game Has Exited.\n");
	else if (game->winning_check == 1)
		ft_printf("Congrats! Now Let's Make More Crafts Inside!\n");
	free_map(game->map);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win.mlx_win);
	free(game->mlx);
	exit(0);
}
