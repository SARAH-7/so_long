/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:43:23 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/07 12:01:09 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_parser(char *str)
{
	int i;
	int	j;
	char *file_format;
	file_format = ".ber";
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\0')
	{
		while (str[i] == file_format[j])
		{
			i++;
			j++;	
		}
		if (j == 3 && str[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}