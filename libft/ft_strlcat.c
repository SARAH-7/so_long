/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:35:08 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 17:49:49 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	k;

	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	k = 0;
	if (dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[k] != '\0' && (dstlen + k) < dstsize - 1)
	{
		dst[dstlen + k] = src[k];
		k++;
	}
	dst[dstlen + k] = '\0';
	return (dstlen + ft_strlen(src));
}
