/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:50:15 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/09 17:00:21 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	fd;
	char **test;

	(void)av;
	test = NULL;
	if (ac != 2)
		exit(EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (!file_parser(av[1]) || fd == -1)
	{
		if (!file_parser(av[1]))
			ft_printf("Wrong File Format\n");
		return (1);
	}
	map_parser(fd);
	// test = map_parser(fd);
	// ft_printf("[%s]\n", *test);
}