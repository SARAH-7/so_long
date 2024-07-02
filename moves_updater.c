/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:43:04 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:13:25 by sbakhit          ###   ########.fr       */
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

int	move_flag(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
	{
		game->player.collectable_counter++;
		game->map[i][j] = '0';
		return (1);
	}
	if (game->map[i][j] == '1')
		return (0);
	if (game->map[i][j] == 'E' && (game->player.collectable_counter
		!= game->collectable_counter))
		return (3);
	if (game->map[i][j] == 'E' && (game->player.collectable_counter
		== game->collectable_counter))
		return (2);
	return (1);
}

void	update_game(t_game *game)
{
	game->player.moves_counter++;
	player_find(game);
	ft_draw_tiles(*game);
	printf("Moves: %d\n", game->player.moves_counter);
}
