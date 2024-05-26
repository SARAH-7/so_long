/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:46:31 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/26 17:31:48 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_game game)
{
	int		i;
	int		j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] != '1')
				mlx_put_image_to_window(game.mlx, game.win.mlx_win,
					game.album[5].img, j * DIM, i * DIM);
			j++;
		}
		i++;
	}
}

void	put_image(t_game game, int i, int j, int flag)
{
	if (game.map[i][j] == '1')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[0].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'C')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[1].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'P' && flag == 0)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[2].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'P' && flag == 1)
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[3].img, j * DIM, i * DIM);
	if (game.map[i][j] == 'E')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[4].img, j * DIM, i * DIM);
	if (game.map[i][j] == '0')
		mlx_put_image_to_window(game.mlx, game.win.mlx_win,
			game.album[5].img, j * DIM, i * DIM);
}

void	ft_draw_tiles(t_game game, int flag)
{
	int		i;
	int		j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			put_image(game, i, j, flag);
			j++;
		}
		i++;
	}
}