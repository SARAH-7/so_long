/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:14:57 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 16:16:47 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	// int	i;

	len = ft_strlen(s);
	// i = 0;
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			return (&((char *)s)[len]);
			break ;
		}
		len--;
		// i++;
	}
	return (NULL);
}
