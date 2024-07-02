/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:21:16 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 14:36:23 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;

	len = f_numlen(n);
	num = n;
	if (n < 0)
		num *= -1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	str[len] = 0;
	if (num == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (len-- && num != 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
