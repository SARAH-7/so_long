/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:41:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/17 13:51:20 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdbool.h>

static int	formats_fun(const char **format, va_list args)
{
	int	counter;

	counter = 0;
	if (**format == 'c')
		counter += ft_putchar(va_arg(args, int));
	if (**format == 's')
		counter += ft_putstr(va_arg(args, char *));
	if (**format == 'd' || **format == 'i')
		counter += ft_putnbr(va_arg(args, int), counter);
	if (**format == 'u')
		counter += ft_putunsigned_int(va_arg(args, int));
	if (**format == 'p')
		counter += ft_putpointer(va_arg(args, void *));
	if (**format == 'x')
		counter += ft_putnbr_hex((unsigned int)va_arg(args, unsigned int));
	if (**format == 'X')
		counter += ft_putnbr_hex_cap((unsigned int)va_arg(args, unsigned int));
	if (**format == '%')
		counter += ft_putchar('%');
	format++;
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				str_counter;

	str_counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
			str_counter += ft_putchar(*format);
		else
		{
			format++;
			str_counter += formats_fun(&format, args);
		}
	}
	va_end(args);
	return (str_counter);
}