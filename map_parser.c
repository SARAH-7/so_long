/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:10:31 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/11 18:47:40 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_parser(int fd)
{
    char *line = NULL;
    char **map = NULL;
    int i = 0;
    map = (char **)malloc(sizeof(char *) * (9999));
	line = get_next_line(fd);
	if (!map || !line)
		return (close(fd), NULL);
	map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	ft_strlcpy(map[i++], line, (ft_strlen(line) + 1));
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			map[i] = NULL;
			break ;
		}
		map[i] = (char *)malloc(1 * (ft_strlen(line) + 1));
		ft_strlcpy(map[i++], line, (ft_strlen(line) + 1));
		free(line);
	}
	return (close(fd), map);
}