/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:09:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/12 20:17:19 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int counter)
{
	if (n == -2147483648)
	{
		return (counter + ft_putstr("-2147483648"));
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		return (ft_putnbr(-n, counter));
	}
	if (n > 9)
		counter = ft_putnbr(n / 10, counter);
	return (counter + ft_putchar(n % 10 + '0'));
}
