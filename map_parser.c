/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:10:31 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/05 02:49:54 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_width(char *map_row)
{
	int	i;

	i = 0;
	if (!map_row)
		return (0);
	while (map_row[i])
		i++;
	if (i > 53)
	{
		ft_printf("You Exceed The Possible Window Width!\n");
		return (0);
	}
	return (i);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[i])
		return (0);
	while (map[i])
		i++;
	if (i > 29)
	{
		ft_printf("You Exceed The Possible Window Height!\n");
		return (0);
	}
	return (i);
}

char	*assign_map(char **map, char *line, int *i)
{
	map[*i] = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	if (!map[*i])
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	ft_strlcpy(map[*i], line, (ft_strlen(line) + 1));
	free(line);
	return (map[(*i)]);
}

char	**map_parser(int fd)
{
	char	*line;
	char	**map;
	int		i;

	line = NULL;
	i = 0;
	map = ft_calloc(sizeof(char *), 9999);
	line = get_next_line(fd);
	if (!map || !line)
	{
		close(fd);
		error_print_msg(6, map);
	}
	while (line != NULL)
	{
		map[i++] = assign_map(map, line, &i);
		line = get_next_line(fd);
	}
	check_for_walls(map, i);
	return (close(fd), map);
}
