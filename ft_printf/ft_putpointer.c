/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:03:40 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/12 20:17:26 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	counter += ft_putnbr_hex((unsigned long)ptr);
	return (counter);
}
