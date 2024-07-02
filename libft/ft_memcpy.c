/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:36:49 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 16:09:56 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*org_dst;

	if (!src && !dst)
		return (NULL);
	org_dst = dst;
	while (n--)
	{
		*(char *)dst++ = *(char *)src++;
	}
	return (org_dst);
}
