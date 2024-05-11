/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:39:51 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/11 22:03:57 by sbakhit          ###   ########.fr       */
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