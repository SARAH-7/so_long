/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:10:31 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/08 20:52:56 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_parser(int fd)
{
    char *line = NULL;
    static int line_counter = 0;
    static int line_length = 0;
    int length = 0;
    int **map = NULL;
	struct s_game game;
    int i = 0;

	game.player_checker = 0;
	game.collectable_checker = 0;
	game.exit_checker = 0;
    line = get_next_line(fd);
    if (line)
    {
        line_counter++;
        length = ft_strlen(line) - 1;
        // ft_printf("%s", line);
        map = malloc(length * sizeof(int*));
        if (map == NULL)
        {
            ft_printf("Memory allocation error!\n");
            exit(EXIT_FAILURE);
        }
        while (i < length)
        {
            map[i] = malloc(line_length * sizeof(int));
            if (map[i] == NULL)
            {
                ft_printf("Memory allocation error!\n");
                exit(EXIT_FAILURE);
            }
            i++;
        }
        i = 0;
        while (line[i++] != '1')
        {
            ft_printf("Error Wall Entry!\n");
            exit(EXIT_FAILURE);
        }
    }
    int j = 1;
    int k = 0;
    while ((line = get_next_line(fd)))
    {
		i = 0;
        k = 0;
        line_counter++;
        line_length = ft_strlen(line) - 1;
        if (line[line_length] != '\n')
            line_length++;
        if (length != line_length)
        {
            ft_printf("Unaligned Map!\n");
            exit(EXIT_FAILURE);
        }
		while (line[i])
		{
			if (line[i] == 'P')
				game.player_checker++;
			if (line[i] == 'C')
				game.collectable_checker++;
			if (line[i] == 'E')
				game.exit_checker++;
            if ((line[i] != '1' && (i == 0 || i == line_length - 1)) || line_length == line_counter)
            {
                ft_printf("Invalid Map Enteries!\n");
		        exit(EXIT_FAILURE);
            }
			i++;
		}
		ft_strlcpy((char *)map[j], line, line_length + 1);
        // ft_printf("%s\n", map[j]);
        j++;
        free(line);
    }
    j = line_counter - 1;
    k = 0;
    ft_printf("[%s]\n", map[j]);
    while (map[j][k] != '\0')
    {
        ft_printf("[%c]\n", map[j][k]);
        if (map[j][k] != '1')
        {
            ft_printf("Error Wall Entry!\n");
            exit(EXIT_FAILURE);
        }
        k++;
    }

	if (line_counter <= 1 || game.player_checker != 1 || game.exit_checker != 1 || game.collectable_checker < 1)
	{
		ft_printf("Invalid Map Enteries!\n");
		exit(EXIT_FAILURE);
	}
    for (int i = 0; i < length; i++)
    {
        free(map[i]);
    }
    free(map);
    return ((char **)map);
}
