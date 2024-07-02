/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:10:16 by sbakhit           #+#    #+#             */
/*   Updated: 2024/01/03 18:00:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	size_t		effective_len;
	char		*substring;
	size_t		i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		effective_len = s_len - start;
	else
		effective_len = len;
	substring = malloc((effective_len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < effective_len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[effective_len] = '\0';
	return (substring);
}
