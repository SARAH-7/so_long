/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:43:04 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:13:55 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	int	i;
	int	j;
	int	move_result;

	j = game->player.position_x / DIM;
	i = (game->player.position_y / DIM) - 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1 || move_result == 2)
	{
		ft_draw_tiles(*game);
		game->map[i][j] = 'P';
		game->map[i + 1][j] = '0';
		update_game(game);
	}
	if (move_result == 3)
		printf("Collect all coins first!\n");
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	return (0);
}

int	move_left(t_game *game)
{
	int	i;
	int	j;
	int	move_result;

	j = game->player.position_x / DIM - 1;
	i = game->player.position_y / DIM;
	game->player.direction = 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game);
		game->map[i][j] = 'P';
		game->map[i][j + 1] = '0';
		update_game(game);
	}
	if (move_result == 3)
		printf("Collect all coins first!\n");
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	return (0);
}

int	move_down(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.position_x / DIM;
	i = game->player.position_y / DIM + 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game);
		game->map[i][j] = 'P';
		game->map[i - 1][j] = '0';
		update_game(game);
	}
	if (move_result == 3)
		printf("Collect all coins first LOL!\n");
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	return (0);
}

int	move_right(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.position_x / DIM + 1;
	i = game->player.position_y / DIM;
	game->player.direction = 0;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game);
		game->map[i][j] = 'P';
		game->map[i][j - 1] = '0';
		update_game(game);
	}
	if (move_result == 3)
		printf("Collect all coins first LOL!\n");
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	return (0);
}
