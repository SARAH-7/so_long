/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:45:32 by sbakhit           #+#    #+#             */
/*   Updated: 2024/06/03 21:45:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_print_msg(int error_num)
{
	if (error_num == 1)
		ft_printf("Error! Can't Open File.");
	if (error_num == 2)
		ft_printf("Error! Invalid Map Entries.\n");
	if (error_num == 3)
		ft_printf("The Map isn't Fully Surrounded By Walls!\n");
	if (error_num == 4)
		ft_printf("Inconsistent Dimensions For Map!\n");
	if (error_num == 5)
		ft_printf("Error! Your Map is Empty.\n");
	exit(EXIT_FAILURE);
}
