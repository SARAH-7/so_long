/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:45:32 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/28 18:17:28 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_print_msg_pre_map(int error_num)
{
	if (error_num == 1)
		ft_printf("Enter Only Two Arguments.\n");
	if (error_num == 2)
		ft_printf("Enter a Valid File\n");
	if (error_num == 3)
		ft_printf("Error! Can't Open File.");
	exit(EXIT_FAILURE);
}

void	error_print_msg(int error_num, char **map)
{
	if (error_num == 4)
		ft_printf("Error! Invalid Map Entries.\n");
	if (error_num == 5)
		ft_printf("Inconsistent Dimensions For Map!\n");
	if (error_num == 6)
		ft_printf("Error! Your Map is Empty.\n");
	if (error_num == 7)
		ft_printf("There's No Valid Path.\n");
	if (error_num == 8)
		ft_printf("Map Must Be Rectangle.\n");
	free_map(map);
	exit(EXIT_FAILURE);
}
