/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:15 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/11 19:00:36 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;
	char **test;
    // t_game game;

	test = NULL;
	if (ac != 2)
		return (ft_printf("Enter Only Two Arguments\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (!file_parser(av[1]) || fd == -1)
	{
		if (!file_parser(av[1]))
			close(fd);
		return (ft_printf("Enter a Valid File\n"), 1);
	}
	// game.map = map_parser(fd);
	test = map_parser(fd);
    int i = 0;
    while (test[i])
        i++;
    test[i] = NULL;
    i = 0;
    while (test[i] &&  test[i] != NULL)
    {
        ft_printf("[%s]\n", test[i]);
        i++;
    }
	// test = map_parser(fd);
	// ft_printf("[%s]\n", *test);
}