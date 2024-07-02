/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:14:39 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/12 20:17:14 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long long n)
{
	const char	*hex_chars;
	int			counter;

	hex_chars = "0123456789abcdef";
	counter = 0;
	if (n >= 16)
		counter += ft_putnbr_hex(n / 16);
	counter += ft_putchar(hex_chars[n % 16]);
	return (counter);
}
