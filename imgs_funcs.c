/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:45:39 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/26 04:47:05 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	image_parser(t_game game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game.album[i].img == NULL)
			return (0);
		i++;
	}
	// i = 0;
	// while (i < 2)
	// {
	// 	if (game.en_alb[i].img == NULL)
	// 		return (0);
	// 	i++;
	// }
	return (1);
}

void	imgmsg_loadcheck(t_game *game)
{
	if (image_parser(*game) == 0)
	{
		ft_printf("Error! Check all image files are present\n");
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->win.mlx_win);
		destroy_map(game->map);
		exit(0);
	}
}

void	load_images(t_game *game)
{
	game->album[0].img = mlx_xpm_file_to_image(game->mlx,
			"imgs/wall.xpm", &game->album[0].img_width,
			&game->album[0].img_height);
	game->album[1].img = mlx_xpm_file_to_image(game->mlx,
			"imgs/collectable.xpm", &game->album[1].img_width,
			&game->album[1].img_height);
	game->album[2].img = mlx_xpm_file_to_image(game->mlx,
			"imgs/player_right.xpm", &game->album[2].img_width,
			&game->album[2].img_height);
	game->album[3].img = mlx_xpm_file_to_image(game->mlx,
			"imgs/player_left.xpm", &game->album[3].img_width,
			&game->album[3].img_height);
	game->album[4].img = mlx_xpm_file_to_image(game->mlx,
			"imgs/portal.xpm", &game->album[4].img_width,
			&game->album[4].img_height);
	game->album[5].img = mlx_xpm_file_to_image(game->mlx,
			"imgs/background.xpm", &game->album[5].img_width,
			&game->album[5].img_height);
}
