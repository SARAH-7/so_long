/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:57:25 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 16:37:26 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*org_dst;

	if (!dst && !src)
		return (NULL);
	org_dst = dst;
	if (dst <= src || dst >= (src + len))
	{
		while (len--)
			*(char *)dst++ = *(char *)src++;
	}
	else
	{
		dst += len;
		src += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	return (org_dst);
}
