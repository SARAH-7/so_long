/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:43:23 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/03 15:55:22 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_parser(const char *map_path)
{
	static const char	*file_format = ".ber";
	int					i;
	int					j;

	i = ft_strlen(map_path) - 1;
	j = 3;
	while (file_format[j] && map_path[i] == file_format[j] && i >= 0)
	{
		i--;
		j--;
		if (j == -1)
			return (1);
	}
	return (0);
}
