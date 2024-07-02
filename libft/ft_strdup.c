/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:03:37 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 17:59:58 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	char	*dst;

	s = malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	dst = s;
	while (*s1)
		*dst++ = *s1++;
	*dst = '\0';
	return (s);
}
