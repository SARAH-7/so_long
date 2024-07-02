/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/14 15:36:05 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h> //maybe too
# include <stdio.h> //to delete
# include <stdarg.h>

int		ft_putchar(char c);

// int		ft_strlen(const char *s);

int		ft_putstr(char *s);

int		ft_putnbr(int n, int counter);

int		ft_putunsigned_int(unsigned int n);

int		ft_putnbr_hex(unsigned long long n);

int		ft_putnbr_hex_cap(unsigned long long n);

int		ft_putpointer(void *ptr);

int		ft_printf(const char *format, ...);

#endif