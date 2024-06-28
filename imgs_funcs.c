/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:33:21 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/28 12:37:36 by sbakhit          ###   ########.fr       */
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
	return (1);
}

void	imgmsg_loadcheck(t_game *game)
{
	if (!image_parser(*game))
	{
		ft_printf("Error! Check all image files are present\n");
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->win.mlx_win);
		free(game->mlx);
		free_map(game->map);
		exit(EXIT_FAILURE);
	}
}

void	load_images(t_game *game)
{
	game->album[0].img = mlx_xpm_file_to_image(game->mlx,
			"texture/wall.xpm", &game->album[0].img_width,
			&game->album[0].img_height);
	game->album[1].img = mlx_xpm_file_to_image(game->mlx,
			"texture/collectable.xpm", &game->album[1].img_width,
			&game->album[1].img_height);
	game->album[2].img = mlx_xpm_file_to_image(game->mlx,
			"texture/player_right.xpm", &game->album[2].img_width,
			&game->album[2].img_height);
	game->album[3].img = mlx_xpm_file_to_image(game->mlx,
			"texture/player_left.xpm", &game->album[3].img_width,
			&game->album[3].img_height);
	game->album[4].img = mlx_xpm_file_to_image(game->mlx,
			"texture/portal.xpm", &game->album[4].img_width,
			&game->album[4].img_height);
	game->album[5].img = mlx_xpm_file_to_image(game->mlx,
			"texture/background.xpm", &game->album[5].img_width,
			&game->album[5].img_height);
}
