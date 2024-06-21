/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 01:28:41 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/21 14:32:07 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_wall(t_game *game, int i, int j, int flag)
{
	mlx_put_image_to_window(game->mlx, game->win.mlx_win,
		game->album[5].img, j * DIM, i * DIM);
	bonus_ft_draw_tiles(*game, flag);
}

int	move_up(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.position_x / DIM;
	i = (game->player.position_y / DIM) - 1;
	game->player.direction = 3;
	move_result = bonus_move_flag(game, i, j);
	if (move_result == 0)
		move_wall(game, i + 1, j, game->player.direction);
	else if (move_result == 1)
	{
		bonus_ft_draw_tiles(*game, game->player.direction);
		game->map[i][j] = 'P';
		game->map[i + 1][j] = '0';
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
	else if (move_result == 2)
	{
		game->winning_check = 1;
		bonus_destroy_game_post(game);
	}
	else if (move_result == 4)
		return (1);
	// bonus_update_game(game);
	return (0);
}

int	move_left(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.position_x / DIM - 1;
	i = game->player.position_y / DIM;
	game->player.direction = 1;
	move_result = bonus_move_flag(game, i, j);
	if (move_result == 0)
		move_wall(game, i, j + 1, game->player.direction);
	else if (move_result == 1)
	{
		bonus_ft_draw_tiles(*game, game->player.direction);
		game->map[i][j] = 'P';
		game->map[i][j + 1] = '0';
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
	else if (move_result == 2)
	{
		game->winning_check = 1;
		bonus_destroy_game_post(game);
	}
	else if (move_result == 4)
		return (1);
	// bonus_update_game(game);
	return (0);
}

int	move_down(t_game *game)
{
	int		i;
	int		j;
	int		move_result;

	j = game->player.position_x / DIM;
	i = game->player.position_y / DIM + 1;
	move_result = bonus_move_flag(game, i, j);
	if (move_result == 0)
		move_wall(game, i - 1, j, game->player.direction);
	else if (move_result == 1)
	{
		bonus_ft_draw_tiles(*game, game->player.direction);
		game->map[i][j] = 'P';
		game->map[i - 1][j] = '0';
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
	else if (move_result == 2)
	{
		game->winning_check = 1;
		bonus_destroy_game_post(game);
	}
	else if (move_result == 4)
		return (1);
	// bonus_update_game(game);
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
	move_result = bonus_move_flag(game, i, j);
	if (move_result == 0)
		move_wall(game, i, j - 1, game->player.direction);
	else if (move_result == 1)
	{
		bonus_ft_draw_tiles(*game, game->player.direction);
		game->map[i][j] = 'P';
		game->map[i][j - 1] = '0';
	}
	if (move_result == 3)
		ft_printf("First, Eat All the Meat!\n");
	else if (move_result == 2)
	{
		game->winning_check = 1;
		bonus_destroy_game_post(game);
	}
	else if (move_result == 4)
		return (1);
	// bonus_update_game(game);
	return (0);
}
