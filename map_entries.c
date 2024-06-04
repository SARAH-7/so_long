/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:40:29 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/05 02:28:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_last_wall(char **map, int height, int i)
{
	int	j;

	j = 0;
	while ((i == 0 && map[i][j] != '\0')
		|| (i == height - 1 && map[i][j] != '\0'))
	{
		if (map[i][j] != '1')
		{
			error_print_msg(3);
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_borders(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if ((j == 0 || j == (int)ft_strlen(map[i]) - 1)
			&& map[i][j] != '1')
		{
			error_print_msg(3);
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_for_walls(char **map, int map_height)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != NULL)
	{
		if (i == 0 || i == map_height - 1)
		{
			if (!check_first_last_wall(map, map_height, i))
				return (0);
		}
		else
		{
			if (!check_borders(map, i))
				return (0);
		}
		if (map[i + 1] != NULL
			&& (int)ft_strlen(map[i]) != (int)ft_strlen(map[i + 1]))
		{
			error_print_msg(4);
			return (0);
		}
		i++;
	}
	return (1);
}
