/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:31:51 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/03 19:12:52 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker(t_game *game)
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
				return (0);
			j++;
		}
		i++;
	}
	if (game->player_checker == 1 && game->collectable_counter >= 1
		&& game->exit_checker == 1)
		return (1);
	else
		return (0);
}
