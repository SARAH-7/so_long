/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:40:29 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/03 21:40:58 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_last_wall(char **map, int map_height, int i)
{
	int	j;

	j = 0;
	while ((i == 0 && map[i][j] != '\0')
		|| (i == map_height - 1 && map[i][j] != '\0'))
	{
		if (map[i][j] != '1')
			error_print_msg(3);
		j++;
	}
}

void	check_borders(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if ((j == 0 || j == (int)ft_strlen(map[i]) - 1)
			&& map[i][j] != '1')
			error_print_msg(3);
		j++;
	}
}

void	check_for_walls(char **map, int map_height)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != NULL)
	{
		if (i == 0 || i == map_height - 1)
			check_first_last_wall(map, map_height, i);
		else
			check_borders(map, i);
		if (map[i + 1] != NULL
			&& (int)ft_strlen(map[i]) != (int)ft_strlen(map[i + 1]))
			error_print_msg(4);
		i++;
	}
}
