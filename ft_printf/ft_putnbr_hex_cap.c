/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:19:19 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/12 20:17:07 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_cap(unsigned long long n)
{
	const char	*hex_chars;
	int			counter;

	hex_chars = "0123456789ABCDEF";
	counter = 0;
	if (n >= 16)
		counter += ft_putnbr_hex_cap(n / 16);
	counter += ft_putchar(hex_chars[n % 16]);
	return (counter);
}
