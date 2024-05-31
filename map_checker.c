/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:31:51 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/27 20:17:00 by sbakhit          ###   ########.fr       */
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
			if (game->map[i][j] == 'C')
				game->collectable_checker++;
			if (game->map[i][j] == 'E')
				game->exit_checker++;
			j++;
		}
		i++;
	}
	if (game->player_checker == 1 && game->collectable_checker >= 1
		&& game->exit_checker == 1)
		return (1);
	else
		return (0);
}
