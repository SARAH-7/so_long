/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:11 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/12 20:17:34 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_int(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 9)
	{
		counter += ft_putnbr(n / 10, counter);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}
