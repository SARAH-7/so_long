/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:20:36 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/12 20:17:30 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	counter;

	counter = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		counter = 6;
	}
	else
		counter += write(1, s, strlen(s));
	return (counter);
}
