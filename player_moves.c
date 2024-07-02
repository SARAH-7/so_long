/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:11:01 by sbakhit           #+#    #+#             */
/*   Updated: 2024/07/02 19:14:12 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	int	i;
	int	j;
	int	move_result;

	j = game->player.position_x / DIM;
	i = (game->player.position_y / DIM) - 1;
	move_result = move_flag(game, i, j);
	if (move_result == 1)
	{
		ft_draw_tiles(*game);
		game->map[i][j] = 'P';
		game->map[i + 1][j] = '0';
		update_game(game);
	}
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
}

void	move_left(t_game *game)
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
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
}

void	move_down(t_game *game)
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
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
}

void	move_right(t_game *game)
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
	if (move_result == 2)
	{
		game->winning_check = 1;
		destroy_game_post(game);
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
}
