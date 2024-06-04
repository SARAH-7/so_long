/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:10:31 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/03 22:12:53 by sbakhit          ###   ########.fr       */
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
		ft_printf("You Exceed The Possible Window Width!");
		exit(EXIT_FAILURE);
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
		ft_printf("You Exceed The Possible Window Height!");
		exit(EXIT_FAILURE);
	}
	return (i);
}

char	**map_parser(int fd)
{
	char	*line;
	char	**map;
	int		i;

	line = NULL;
	map = NULL;
	i = 0;
	map = (char **)malloc(sizeof(char *) * (9999));
	line = get_next_line(fd);
	if (!map || !line)
	{
		error_print_msg(5);
		return (close(fd), NULL);
	}
	line[ft_strlen(line) - 1] = '\0';
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	ft_strlcpy(map[i++], line, (ft_strlen(line) + 1));
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_strlcpy(map[i++], line, (ft_strlen(line) + 1));
		free(line);
	}
	map[i] = NULL;
	check_for_walls(map, i);
	return (close(fd), map);
}
